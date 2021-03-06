/**
 * TitaniumKit
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_TEXTFIELD_HPP_
#define _TITANIUM_UI_TEXTFIELD_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/Constants.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.TextField module.

		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.TextField
		*/
		class TITANIUMKIT_EXPORT TextField : public View, public JSExport<TextField>
		{
		public:
			/*!
			  @method

			  @abstract autocapitalization : Number

			  @discussion Determines how text is capitalized during typing.
			*/
			virtual TEXT_AUTOCAPITALIZATION get_autocapitalization() const TITANIUM_NOEXCEPT final;
			virtual void set_autocapitalization(const TEXT_AUTOCAPITALIZATION& autocapitalization) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract borderStyle : Number

			  @discussion Border style for the field.
			*/
			virtual INPUT_BORDERSTYLE get_borderStyle() const TITANIUM_NOEXCEPT final;
			virtual void set_borderStyle(const INPUT_BORDERSTYLE& borderStyle) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract clearButtonMode : Number

			  @discussion Determines when the clear button is displayed.
			*/
			virtual INPUT_BUTTONMODE get_clearButtonMode() const TITANIUM_NOEXCEPT final;
			virtual void set_clearButtonMode(const INPUT_BUTTONMODE& clearButtonMode) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract color : String

			  @discussion Color of the text in this text field, as a color name or hex triplet.
			*/
			virtual std::string get_color() const TITANIUM_NOEXCEPT final;
			virtual void set_color(const std::string& color) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract editable : Boolean

			  @discussion Determines whether this field can be edited.
			*/
			virtual bool get_editable() const TITANIUM_NOEXCEPT final;
			virtual void set_editable(const bool& editable) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract ellipsize : Boolean

			  @discussion Determines whether an ellipsis (...) should be used to indicate truncated text.
			*/
			virtual bool get_ellipsize() const TITANIUM_NOEXCEPT final;
			virtual void set_ellipsize(const bool& ellipsize) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract enableReturnKey : Boolean

			  @discussion Determines whether the return key is enabled automatically when there is text in this text field.

			  If true, the return key is disabled when this text field is empty, and automatically enabled as soon as the user types any text in the field.

			  On Android, if true, return event will not fire. Clicking on the return key will do nothing, but the key itself won't be disabled.
			*/
			virtual bool get_enableReturnKey() const TITANIUM_NOEXCEPT final;
			virtual void set_enableReturnKey(const bool& enableReturnKey) TITANIUM_NOEXCEPT;

// TODO font!

			/*!
			  @method

			  @abstract hintText : String

			  @discussion Hint text to display when the field is empty.

			  Hint text is hidden when the user enters text into this text field.

			  Use the backslash and letter n line feed character combination, ie \n, to force a new line.

			  Use unicode characters, such as those included in (but not limited to) the Unicode List of Useful Symbols section of wikipedia, to insert special characters and symbols.
			*/
			virtual std::string get_hintText() const TITANIUM_NOEXCEPT final;
			virtual void set_hintText(const std::string& hintText) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract keyboardType : Number

			  @discussion Keyboard type to display when this text field is
			  focused. When asking for a specific kind of user input, such as a
			  phone number or email address, you should always specify the
			  appropriate keyboard type.
			*/
			virtual KEYBOARD get_keyboardType() const TITANIUM_NOEXCEPT final;
			virtual void set_keyboardType(const KEYBOARD& keyboardType) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract leftButtonMode : Number

			  @discussion Determines when to display the left button view.
			*/
			virtual INPUT_BUTTONMODE get_leftButtonMode() const TITANIUM_NOEXCEPT final;
			virtual void set_leftButtonMode(const INPUT_BUTTONMODE& leftButtonMode) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract maxLength : Number

			  @discussion Maximum length of text field input.

			  Any attempt to input text beyond this length (including pasting a string larger than maxLength) will not edit the field's contents. A value of -1 indicates unlimited length.
			*/
			virtual int32_t get_maxLength() const TITANIUM_NOEXCEPT final;
			virtual void set_maxLength(const int32_t& maxLength) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract passwordMask : Boolean

			  @discussion Obscure the input text from the user.

			  Set to true to hide entered characters.

			  On Mobile Web, if you set a keyboardType and enable the passwordMask, the passwordMask will always take precedence and the default keyboard will be used.

			  Note: on iOS, passwordMask must be specified when this text field is created.
			*/
			virtual bool get_passwordMask() const TITANIUM_NOEXCEPT final;
			virtual void set_passwordMask(const bool& passwordMask) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract returnKeyType : Number

			  @discussion Specifies the text to display on the keyboard Return key when this field is focused.
			*/
			virtual RETURNKEY get_returnKeyType() const TITANIUM_NOEXCEPT final;
			virtual void set_returnKeyType(const RETURNKEY& returnKeyType) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract rightButtonMode : Number

			  @discussion Determines when to display the right button view.
			*/
			virtual INPUT_BUTTONMODE get_rightButtonMode() const TITANIUM_NOEXCEPT final;
			virtual void set_rightButtonMode(const INPUT_BUTTONMODE& rightButtonMode) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract suppressReturn : String/Number

			  @discussion Determines whether the return key should be suppressed during entry.
			*/
			virtual bool get_suppressReturn() const TITANIUM_NOEXCEPT final;
			virtual void set_suppressReturn(const bool& suppressReturn) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract textAlign : String/Number

			  @discussion Text alignment within this text field.
			*/
			virtual TEXT_ALIGNMENT get_textAlign() const TITANIUM_NOEXCEPT final;
			virtual void set_textAlign(const TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract value : String

			  @discussion Value of this text field, which may be set programmatically and modified by the user.

			  Use the backslash and letter n line feed character combination, ie \n, to force a new line.

			  Use unicode characters, such as those included in (but not limited to) the Unicode List of Useful Symbols section of wikipedia, to insert special characters and symbols.
			*/
			virtual std::string get_value() const TITANIUM_NOEXCEPT;
			virtual void set_value(const std::string& value) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract verticalAlign : Number/String

			  @discussion Vertical alignment within this text field.
			*/
			virtual TEXT_VERTICAL_ALIGNMENT get_verticalAlign() const TITANIUM_NOEXCEPT final;
			virtual void set_verticalAlign(const TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract blur() : void

			  @discussion Forces the field to lose focus.

			  @param

			  @result void
			*/
			virtual void blur() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract focus() : void

			  @discussion Forces the field to gain focus.

			  @param 

			  @result void
			*/
			virtual void focus() TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract hasText() : Boolean

			  @discussion Returns true if this text field contains text.

			  @param 

			  @result bool
			*/
			virtual bool hasText() TITANIUM_NOEXCEPT;

			TextField(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~TextField() = default;
			TextField(const TextField&) = default;
			TextField& operator=(const TextField&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TextField(TextField&&) = default;
			TextField& operator=(TextField&&) = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(autocapitalization);
			TITANIUM_FUNCTION_DEF(getAutocapitalization);
			TITANIUM_FUNCTION_DEF(setAutocapitalization);

			TITANIUM_PROPERTY_DEF(borderStyle);
			TITANIUM_FUNCTION_DEF(getBorderStyle);
			TITANIUM_FUNCTION_DEF(setBorderStyle);

			TITANIUM_PROPERTY_DEF(clearButtonMode);
			TITANIUM_FUNCTION_DEF(getClearButtonMode);
			TITANIUM_FUNCTION_DEF(setClearButtonMode);

			TITANIUM_PROPERTY_DEF(color);
			TITANIUM_FUNCTION_DEF(getColor);
			TITANIUM_FUNCTION_DEF(setColor);

			TITANIUM_PROPERTY_DEF(editable);
			TITANIUM_FUNCTION_DEF(getEditable);
			TITANIUM_FUNCTION_DEF(setEditable);

			TITANIUM_PROPERTY_DEF(ellipsize);
			TITANIUM_FUNCTION_DEF(getEllipsize);
			TITANIUM_FUNCTION_DEF(setEllipsize);

			TITANIUM_PROPERTY_DEF(enableReturnKey);
			TITANIUM_FUNCTION_DEF(getEnableReturnKey);
			TITANIUM_FUNCTION_DEF(setEnableReturnKey);

			TITANIUM_PROPERTY_DEF(hintText);
			TITANIUM_FUNCTION_DEF(getHintText);
			TITANIUM_FUNCTION_DEF(setHintText);

			TITANIUM_PROPERTY_DEF(keyboardType);
			TITANIUM_FUNCTION_DEF(getKeyboardType);
			TITANIUM_FUNCTION_DEF(setKeyboardType);

			TITANIUM_PROPERTY_DEF(leftButtonMode);
			TITANIUM_FUNCTION_DEF(getLeftButtonMode);
			TITANIUM_FUNCTION_DEF(setLeftButtonMode);

			TITANIUM_PROPERTY_DEF(maxLength);
			TITANIUM_FUNCTION_DEF(getMaxLength);
			TITANIUM_FUNCTION_DEF(setMaxLength);

			TITANIUM_PROPERTY_DEF(passwordMask);
			TITANIUM_FUNCTION_DEF(getPasswordMask);
			TITANIUM_FUNCTION_DEF(setPasswordMask);

			TITANIUM_PROPERTY_DEF(returnKeyType);
			TITANIUM_FUNCTION_DEF(getReturnKeyType);
			TITANIUM_FUNCTION_DEF(setReturnKeyType);

			TITANIUM_PROPERTY_DEF(rightButtonMode);
			TITANIUM_FUNCTION_DEF(getRightButtonMode);
			TITANIUM_FUNCTION_DEF(setRightButtonMode);

			TITANIUM_PROPERTY_DEF(suppressReturn);
			TITANIUM_FUNCTION_DEF(getSuppressReturn);
			TITANIUM_FUNCTION_DEF(setSuppressReturn);

			TITANIUM_PROPERTY_DEF(textAlign);
			TITANIUM_FUNCTION_DEF(getTextAlign);
			TITANIUM_FUNCTION_DEF(setTextAlign);

			TITANIUM_PROPERTY_DEF(value);
			TITANIUM_FUNCTION_DEF(getValue);
			TITANIUM_FUNCTION_DEF(setValue);

			TITANIUM_PROPERTY_DEF(verticalAlign);
			TITANIUM_FUNCTION_DEF(getVerticalAlign);
			TITANIUM_FUNCTION_DEF(setVerticalAlign);

			TITANIUM_FUNCTION_DEF(blur);
			TITANIUM_FUNCTION_DEF(focus);
			TITANIUM_FUNCTION_DEF(hasText);

		private:
#pragma warning(push)
#pragma warning(disable : 4251)
			TEXT_AUTOCAPITALIZATION autocapitalization__;
			INPUT_BORDERSTYLE borderStyle__;
			INPUT_BUTTONMODE clearButtonMode__;
			std::string color__;
			bool editable__;
			bool ellipsize__;
			bool enableReturnKey__;
			std::string hintText__;
			KEYBOARD keyboardType__;
			INPUT_BUTTONMODE leftButtonMode__;
			int32_t maxLength__;
			bool passwordMask__;
			RETURNKEY returnKeyType__;
			INPUT_BUTTONMODE rightButtonMode__;
			bool suppressReturn__;
			TEXT_ALIGNMENT textAlign__;
			std::string value__;
			TEXT_VERTICAL_ALIGNMENT verticalAlign__;
#pragma warning(pop)
		};
	} // namespace UI
}  // namespace Titanium

#endif  // _TITANIUM_UI_TEXTFIELD_HPP_
