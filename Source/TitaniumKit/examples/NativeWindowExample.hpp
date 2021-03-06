/**
 * TitaniumKit
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_EXAMPLES_NATIVEWINDOWEXAMPLE_HPP_
#define _TITANIUM_EXAMPLES_NATIVEWINDOWEXAMPLE_HPP_

#include "Titanium/Titanium.hpp"

using namespace HAL;

/*!
 @class
 
 @discussion This is an example of how to implement Titanium::UI::Window
 for a native platform.
 */
class NativeWindowExample final : public Titanium::UI::Window, public JSExport<NativeWindowExample>
{
public:
	virtual void open(const std::shared_ptr<Titanium::UI::OpenWindowParams>& params) TITANIUM_NOEXCEPT override final;

	NativeWindowExample(const JSContext&) TITANIUM_NOEXCEPT;

	virtual ~NativeWindowExample() TITANIUM_NOEXCEPT;  //= default;
	NativeWindowExample(const NativeWindowExample&) = default;
	NativeWindowExample& operator=(const NativeWindowExample&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
	NativeWindowExample(NativeWindowExample&&) = default;
	NativeWindowExample& operator=(NativeWindowExample&&) = default;
#endif

	static void JSExportInitialize();
};

#endif  // _TITANIUM_EXAMPLES_NATIVEWINDOWEXAMPLE_HPP_
