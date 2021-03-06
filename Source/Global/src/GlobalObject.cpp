/**
 * Global for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/GlobalObject.hpp"
#include "Titanium/detail/TiBase.hpp"
#include <ratio>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	static Platform::String^ resolve(const std::string& path) 
	{
		const auto newpath = TitaniumWindows::Utility::ConvertUTF8String(boost::algorithm::replace_all_copy(path, "/", "\\"));

		Windows::ApplicationModel::Package^ package = Windows::ApplicationModel::Package::Current;
		Windows::Storage::StorageFolder^ installed_location = package->InstalledLocation;
		Platform::String^ location = installed_location->Path;

		return location + "\\" + newpath;
	}

	bool GlobalObject::requiredModuleExists(const std::string& path) const TITANIUM_NOEXCEPT
	{
		auto module_path = resolve(path);
		TITANIUM_LOG_DEBUG("GlobalObject::requiredModuleExists: ", TitaniumWindows::Utility::ConvertUTF8String(module_path));

		bool exists = false;
		concurrency::event event;
		concurrency::task<Windows::Storage::StorageFile^>(Windows::Storage::StorageFile::GetFileFromPathAsync(module_path)).then([&exists, &event](concurrency::task<Windows::Storage::StorageFile^> task) {
			try {
				task.get();
				exists = true;
			} catch (Platform::COMException^ ex) {
				exists = false;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
		event.wait();

		return exists;
	}

	std::string GlobalObject::readRequiredModule(const std::string& path) const
	{
		auto module_path = resolve(path);
		TITANIUM_LOG_DEBUG("GlobalObject::loadRequiredModule: module_path = ", TitaniumWindows::Utility::ConvertUTF8String(module_path));

		Platform::String^ content;
		bool hasError = false;
		concurrency::event event;
		concurrency::task<Windows::Storage::StorageFile^>(Windows::Storage::StorageFile::GetFileFromPathAsync(module_path)).then([&content, &hasError, &event](concurrency::task<Windows::Storage::StorageFile^> task) {
			try {
				concurrency::task<Platform::String^>(Windows::Storage::FileIO::ReadTextAsync(task.get(), Windows::Storage::Streams::UnicodeEncoding::Utf8)).then([&content, &hasError, &event](concurrency::task<Platform::String^> task) {
					content = task.get();
					event.set();
				}, concurrency::task_continuation_context::use_arbitrary());
			} catch (Platform::COMException^ ex) {
				hasError = true;
				event.set();
			}
		}, concurrency::task_continuation_context::use_arbitrary());
		event.wait();

		if (hasError) {
			detail::ThrowRuntimeError("require", "Could not load module: module_path = " + TitaniumWindows::Utility::ConvertUTF8String(module_path));
		}

		return TitaniumWindows::Utility::ConvertUTF8String(content);
	}

#pragma warning(push)
#pragma warning(disable : 4251)
	class TITANIUMWINDOWS_GLOBAL_EXPORT Timer final : public Titanium::GlobalObject::Timer, public std::enable_shared_from_this<Timer>
	{
#pragma warning(pop)
	public:
		Timer(Titanium::GlobalObject::Callback_t callback, const std::chrono::milliseconds& interval)
		    : Titanium::GlobalObject::Timer(callback, interval), callback__(callback)
		{
			TITANIUM_LOG_DEBUG("Timer: ctor");

			// A Windows::Foundation::TimeSpan is a time period expressed in
			// 100-nanosecond units.
			//
			// Reference:
			// http://msdn.microsoft.com/en-us/library/windows/apps/windows.foundation.timespan
			std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> timer_interval_ticks = interval;
			TITANIUM_LOG_DEBUG("Timer: ctor: timer_interval_ticks = ", timer_interval_ticks.count());

			Windows::Foundation::TimeSpan time_span;
			time_span.Duration = timer_interval_ticks.count();
			dispatcher_timer__ = ref new Windows::UI::Xaml::DispatcherTimer();
			dispatcher_timer__->Interval = time_span;
		}

		virtual ~Timer()
		{
			TITANIUM_LOG_DEBUG("Timer: dtor");
			if (dispatcher_timer__->IsEnabled) {
				dispatcher_timer__->Stop();
			}

			// TODO: what happens if start was never called? Is this an error?
			dispatcher_timer__->Tick -= event_registration_token__;
			dispatcher_timer__ = nullptr;
		}

		virtual void Start() TITANIUM_NOEXCEPT override final
		{
			TITANIUM_LOG_DEBUG("Timer::Start");
			std::call_once(dispatcher_timer_once_flag__, [this] {
				// Bring in the placeholders _1, _2, etc. for std::bind.
				using namespace std::placeholders;
				std::weak_ptr<Timer> weakThis(shared_from_this());
				auto callback = std::bind([](const std::weak_ptr<Timer>& weakThis, Platform::Object^ sender, Platform::Object^ event) {
						auto strong_ptr = weakThis.lock();
						if (strong_ptr) {
							strong_ptr->callback__();
						}
					},
					std::move(weakThis), _1, _2);
        
				this->event_registration_token__ = this->dispatcher_timer__->Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>(callback);
			});

			if (!(dispatcher_timer__->IsEnabled)) {
				TITANIUM_LOG_DEBUG("Timer::Start: start timer ");
				dispatcher_timer__->Start();
			} else {
				TITANIUM_LOG_WARN("Timer::Start: start called while timer is already running");
			}
		}

		virtual void Stop() TITANIUM_NOEXCEPT override final
		{
			TITANIUM_LOG_DEBUG("Timer::Stop");
			if (dispatcher_timer__->IsEnabled) {
				TITANIUM_LOG_DEBUG("Timer::Stop: stop timer ");
				dispatcher_timer__->Stop();
			} else {
				TITANIUM_LOG_WARN("Timer::Stop: stop called while timer is not running");
			}
		}

	private:
#pragma warning(push)
#pragma warning(disable : 4251)
		Titanium::GlobalObject::Callback_t callback__;
		std::once_flag dispatcher_timer_once_flag__;
#pragma warning(pop)
		Windows::UI::Xaml::DispatcherTimer^ dispatcher_timer__;
		Windows::Foundation::EventRegistrationToken event_registration_token__;
	};

	std::shared_ptr<Titanium::GlobalObject::Timer> GlobalObject::CreateTimer(Titanium::GlobalObject::Callback_t callback, const std::chrono::milliseconds& interval) const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Timer::CreateTimer");
		return std::make_shared<TitaniumWindows::Timer>(callback, interval);
	}
	GlobalObject::GlobalObject(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Titanium::GlobalObject(js_context)
	{
		TITANIUM_LOG_DEBUG("GlobalObject::ctor");
	}

	void GlobalObject::JSExportInitialize()
	{
		JSExport<GlobalObject>::SetClassVersion(1);
		JSExport<GlobalObject>::SetParent(JSExport<Titanium::GlobalObject>::Class());
		TITANIUM_LOG_DEBUG("GlobalObject::ctor CallAsConstructor");
	}

}  // namespace TitaniumWindows {
