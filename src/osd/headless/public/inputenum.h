#pragma once

// absolute devices return values between -65536 and +65536
const int32_t InputAbsoluteMin = -65536;
const int32_t InputAbsoluteMax = 65536;

const int InputMaxAxis = 8;
const int InputMaxButtons = 32;
const int InputMaxHats = 4;
const int InputMaxAddSwitch = 16;
const int InputMaxAddAbsolute = 16;
const int InputMaxAddRelative = 16;


// standard item IDs from input_item_id
typedef NS_ENUM(NSInteger, InputItemID)
{
	InputItemID_INVALID,
	InputItemID_FIRST_VALID,

	// standard keyboard IDs
	InputItemID_A = InputItemID_FIRST_VALID,
	InputItemID_B,
	InputItemID_C,
	InputItemID_D,
	InputItemID_E,
	InputItemID_F,
	InputItemID_G,
	InputItemID_H,
	InputItemID_I,
	InputItemID_J,
	InputItemID_K,
	InputItemID_L,
	InputItemID_M,
	InputItemID_N,
	InputItemID_O,
	InputItemID_P,
	InputItemID_Q,
	InputItemID_R,
	InputItemID_S,
	InputItemID_T,
	InputItemID_U,
	InputItemID_V,
	InputItemID_W,
	InputItemID_X,
	InputItemID_Y,
	InputItemID_Z,
	InputItemID_0,
	InputItemID_1,
	InputItemID_2,
	InputItemID_3,
	InputItemID_4,
	InputItemID_5,
	InputItemID_6,
	InputItemID_7,
	InputItemID_8,
	InputItemID_9,
	InputItemID_F1,
	InputItemID_F2,
	InputItemID_F3,
	InputItemID_F4,
	InputItemID_F5,
	InputItemID_F6,
	InputItemID_F7,
	InputItemID_F8,
	InputItemID_F9,
	InputItemID_F10,
	InputItemID_F11,
	InputItemID_F12,
	InputItemID_F13,
	InputItemID_F14,
	InputItemID_F15,
	InputItemID_F16,
	InputItemID_F17,
	InputItemID_F18,
	InputItemID_F19,
	InputItemID_F20,
	InputItemID_ESC,
	InputItemID_TILDE,
	InputItemID_MINUS,
	InputItemID_EQUALS,
	InputItemID_BACKSPACE,
	InputItemID_TAB,
	InputItemID_OPENBRACE,
	InputItemID_CLOSEBRACE,
	InputItemID_ENTER,
	InputItemID_COLON,
	InputItemID_QUOTE,
	InputItemID_BACKSLASH,
	InputItemID_BACKSLASH2,
	InputItemID_COMMA,
	InputItemID_STOP,
	InputItemID_SLASH,
	InputItemID_SPACE,
	InputItemID_INSERT,
	InputItemID_DEL,
	InputItemID_HOME,
	InputItemID_END,
	InputItemID_PGUP,
	InputItemID_PGDN,
	InputItemID_LEFT,
	InputItemID_RIGHT,
	InputItemID_UP,
	InputItemID_DOWN,
	InputItemID_0_PAD,
	InputItemID_1_PAD,
	InputItemID_2_PAD,
	InputItemID_3_PAD,
	InputItemID_4_PAD,
	InputItemID_5_PAD,
	InputItemID_6_PAD,
	InputItemID_7_PAD,
	InputItemID_8_PAD,
	InputItemID_9_PAD,
	InputItemID_SLASH_PAD,
	InputItemID_ASTERISK,
	InputItemID_MINUS_PAD,
	InputItemID_PLUS_PAD,
	InputItemID_DEL_PAD,
	InputItemID_ENTER_PAD,
	InputItemID_BS_PAD,
	InputItemID_TAB_PAD,
	InputItemID_00_PAD,
	InputItemID_000_PAD,
	InputItemID_COMMA_PAD,
	InputItemID_EQUALS_PAD,
	InputItemID_PRTSCR,
	InputItemID_PAUSE,
	InputItemID_LSHIFT,
	InputItemID_RSHIFT,
	InputItemID_LCONTROL,
	InputItemID_RCONTROL,
	InputItemID_LALT,
	InputItemID_RALT,
	InputItemID_SCRLOCK,
	InputItemID_NUMLOCK,
	InputItemID_CAPSLOCK,
	InputItemID_LWIN,
	InputItemID_RWIN,
	InputItemID_MENU,
	InputItemID_CANCEL,

	// standard mouse/joystick/gun IDs
	InputItemID_XAXIS,
	InputItemID_YAXIS,
	InputItemID_ZAXIS,
	InputItemID_RXAXIS,
	InputItemID_RYAXIS,
	InputItemID_RZAXIS,
	InputItemID_SLIDER1,
	InputItemID_SLIDER2,
	InputItemID_BUTTON1,
	InputItemID_BUTTON2,
	InputItemID_BUTTON3,
	InputItemID_BUTTON4,
	InputItemID_BUTTON5,
	InputItemID_BUTTON6,
	InputItemID_BUTTON7,
	InputItemID_BUTTON8,
	InputItemID_BUTTON9,
	InputItemID_BUTTON10,
	InputItemID_BUTTON11,
	InputItemID_BUTTON12,
	InputItemID_BUTTON13,
	InputItemID_BUTTON14,
	InputItemID_BUTTON15,
	InputItemID_BUTTON16,
	InputItemID_BUTTON17,
	InputItemID_BUTTON18,
	InputItemID_BUTTON19,
	InputItemID_BUTTON20,
	InputItemID_BUTTON21,
	InputItemID_BUTTON22,
	InputItemID_BUTTON23,
	InputItemID_BUTTON24,
	InputItemID_BUTTON25,
	InputItemID_BUTTON26,
	InputItemID_BUTTON27,
	InputItemID_BUTTON28,
	InputItemID_BUTTON29,
	InputItemID_BUTTON30,
	InputItemID_BUTTON31,
	InputItemID_BUTTON32,
	InputItemID_START,
	InputItemID_SELECT,

	// Hats
	InputItemID_HAT1UP,
	InputItemID_HAT1DOWN,
	InputItemID_HAT1LEFT,
	InputItemID_HAT1RIGHT,
	InputItemID_HAT2UP,
	InputItemID_HAT2DOWN,
	InputItemID_HAT2LEFT,
	InputItemID_HAT2RIGHT,
	InputItemID_HAT3UP,
	InputItemID_HAT3DOWN,
	InputItemID_HAT3LEFT,
	InputItemID_HAT3RIGHT,
	InputItemID_HAT4UP,
	InputItemID_HAT4DOWN,
	InputItemID_HAT4LEFT,
	InputItemID_HAT4RIGHT,

	// Additional IDs
	InputItemID_ADD_SWITCH1,
	InputItemID_ADD_SWITCH2,
	InputItemID_ADD_SWITCH3,
	InputItemID_ADD_SWITCH4,
	InputItemID_ADD_SWITCH5,
	InputItemID_ADD_SWITCH6,
	InputItemID_ADD_SWITCH7,
	InputItemID_ADD_SWITCH8,
	InputItemID_ADD_SWITCH9,
	InputItemID_ADD_SWITCH10,
	InputItemID_ADD_SWITCH11,
	InputItemID_ADD_SWITCH12,
	InputItemID_ADD_SWITCH13,
	InputItemID_ADD_SWITCH14,
	InputItemID_ADD_SWITCH15,
	InputItemID_ADD_SWITCH16,

	InputItemID_ADD_ABSOLUTE1,
	InputItemID_ADD_ABSOLUTE2,
	InputItemID_ADD_ABSOLUTE3,
	InputItemID_ADD_ABSOLUTE4,
	InputItemID_ADD_ABSOLUTE5,
	InputItemID_ADD_ABSOLUTE6,
	InputItemID_ADD_ABSOLUTE7,
	InputItemID_ADD_ABSOLUTE8,
	InputItemID_ADD_ABSOLUTE9,
	InputItemID_ADD_ABSOLUTE10,
	InputItemID_ADD_ABSOLUTE11,
	InputItemID_ADD_ABSOLUTE12,
	InputItemID_ADD_ABSOLUTE13,
	InputItemID_ADD_ABSOLUTE14,
	InputItemID_ADD_ABSOLUTE15,
	InputItemID_ADD_ABSOLUTE16,

	InputItemID_ADD_RELATIVE1,
	InputItemID_ADD_RELATIVE2,
	InputItemID_ADD_RELATIVE3,
	InputItemID_ADD_RELATIVE4,
	InputItemID_ADD_RELATIVE5,
	InputItemID_ADD_RELATIVE6,
	InputItemID_ADD_RELATIVE7,
	InputItemID_ADD_RELATIVE8,
	InputItemID_ADD_RELATIVE9,
	InputItemID_ADD_RELATIVE10,
	InputItemID_ADD_RELATIVE11,
	InputItemID_ADD_RELATIVE12,
	InputItemID_ADD_RELATIVE13,
	InputItemID_ADD_RELATIVE14,
	InputItemID_ADD_RELATIVE15,
	InputItemID_ADD_RELATIVE16,

	// generic other IDs
	InputItemID_OTHER_SWITCH,
	InputItemID_OTHER_AXIS_ABSOLUTE,
	InputItemID_OTHER_AXIS_RELATIVE,
	InputItemID_MAXIMUM,

	// internal codes for sequences
	InputItemID_SEQ_END,
	InputItemID_SEQ_DEFAULT,
	InputItemID_SEQ_NOT,
	InputItemID_SEQ_OR,

	// absolute maximum ID
	InputItemID_ABSOLUTE_MAXIMUM = 0xfff
};