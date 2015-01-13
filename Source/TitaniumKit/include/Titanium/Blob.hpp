/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_BLOB_HPP_
#define _TITANIUM_BLOB_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	using namespace HAL;

	/*!
   @class
   @discussion This is the Titanium.Blob module.
   See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Blob
   */
	class TITANIUMKIT_EXPORT Blob : public Module, public JSExport< Blob >
	{
	public:
		/*!
     @method
     @abstract get_length
     @discussion Length of this blob in bytes.
    */
		virtual unsigned get_length() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract get_file
     @discussion File object represented by this blob, or null if this blob is not
                associated with a file.
    */
		virtual JSObject get_file() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract get_height
     @discussion If this blob represents an image, this is the height of the image in pixels.
    */
		virtual unsigned get_height() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract get_mimeType
     @discussion Mime type of the data in this blob.
    */
		virtual std::string get_mimeType() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract get_nativePath
     @discussion If this blob represents a File, this is the file URL that represents it.
    */
		virtual std::string get_nativePath() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract get_size
     @discussion Size of the blob in pixels (for image blobs) or bytes (for all other blobs).
    */
		virtual unsigned get_size() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract get_text
     @discussion UTF-8 string representation of the data in this blob.
    */
		virtual std::string get_text() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract get_width
     @discussion If this blob represents an image, this is the width of the image in pixels.
    */
		virtual unsigned get_width() const TITANIUM_NOEXCEPT;
		/*!
     @method
     @abstract append
     @discussion Appends the data from another blob to this blob.
    */
		virtual void append(std::shared_ptr< Blob >&) TITANIUM_NOEXCEPT;

		Blob(const JSContext& js_context) TITANIUM_NOEXCEPT;
		Blob(const Blob&, const std::vector< JSValue >& arguments) TITANIUM_NOEXCEPT;

		virtual ~Blob() = default;
		Blob(const Blob&) = default;
		Blob& operator=(const Blob&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Blob(Blob&&) = default;
		Blob& operator=(Blob&&) = default;
#endif

		static void JSExportInitialize();

		virtual JSValue get_length_ArgumentValidator() const TITANIUM_NOEXCEPT final;
		virtual JSValue get_file_ArgumentValidator() const TITANIUM_NOEXCEPT final;
		virtual JSValue get_height_ArgumentValidator() const TITANIUM_NOEXCEPT final;
		virtual JSValue get_mimeType_ArgumentValidator() const TITANIUM_NOEXCEPT final;
		virtual JSValue get_nativePath_ArgumentValidator() const TITANIUM_NOEXCEPT final;
		virtual JSValue get_size_ArgumentValidator() const TITANIUM_NOEXCEPT final;
		virtual JSValue get_text_ArgumentValidator() const TITANIUM_NOEXCEPT final;
		virtual JSValue get_width_ArgumentValidator() const TITANIUM_NOEXCEPT final;

		virtual JSValue append_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getFile_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getHeight_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getLength_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getMimeType_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getNativePath_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getSize_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getText_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue getWidth_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
		virtual JSValue toString_ArgumentValidator(const std::vector< JSValue >& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
	};
}  // namespace Titanium {

#endif  // _TITANIUM_BLOB_HPP_
