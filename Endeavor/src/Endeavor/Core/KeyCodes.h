#pragma once

namespace Endeavor
{
	using KeyCode = uint16_t;

	namespace Key
	{
		enum : KeyCode
		{
			// From glfw3.h
			Space = 32,
			Apostrophe = 39, /* ' */
			Comma = 44, /* , */
			Minus = 45, /* - */
			Period = 46, /* . */
			Slash = 47, /* / */

			D0 = 48, /* 0 */
			D1 = 49, /* 1 */
			D2 = 50, /* 2 */
			D3 = 51, /* 3 */
			D4 = 52, /* 4 */
			D5 = 53, /* 5 */
			D6 = 54, /* 6 */
			D7 = 55, /* 7 */
			D8 = 56, /* 8 */
			D9 = 57, /* 9 */

			Semicolon = 59, /* ; */
			Equal = 61, /* = */

			A = 65,
			B = 66,
			C = 67,
			D = 68,
			E = 69,
			F = 70,
			G = 71,
			H = 72,
			I = 73,
			J = 74,
			K = 75,
			L = 76,
			M = 77,
			N = 78,
			O = 79,
			P = 80,
			Q = 81,
			R = 82,
			S = 83,
			T = 84,
			U = 85,
			V = 86,
			W = 87,
			X = 88,
			Y = 89,
			Z = 90,

			LeftBracket = 91,  /* [ */
			Backslash = 92,  /* \ */
			RightBracket = 93,  /* ] */
			GraveAccent = 96,  /* ` */

			World1 = 161, /* non-US #1 */
			World2 = 162, /* non-US #2 */

			/* Function keys */
			Escape = 256,
			Enter = 257,
			Tab = 258,
			Backspace = 259,
			Insert = 260,
			Delete = 261,
			Right = 262,
			Left = 263,
			Down = 264,
			Up = 265,
			PageUp = 266,
			PageDown = 267,
			Home = 268,
			End = 269,
			CapsLock = 280,
			ScrollLock = 281,
			NumLock = 282,
			PrintScreen = 283,
			Pause = 284,
			F1 = 290,
			F2 = 291,
			F3 = 292,
			F4 = 293,
			F5 = 294,
			F6 = 295,
			F7 = 296,
			F8 = 297,
			F9 = 298,
			F10 = 299,
			F11 = 300,
			F12 = 301,
			F13 = 302,
			F14 = 303,
			F15 = 304,
			F16 = 305,
			F17 = 306,
			F18 = 307,
			F19 = 308,
			F20 = 309,
			F21 = 310,
			F22 = 311,
			F23 = 312,
			F24 = 313,
			F25 = 314,

			/* Keypad */
			KP0 = 320,
			KP1 = 321,
			KP2 = 322,
			KP3 = 323,
			KP4 = 324,
			KP5 = 325,
			KP6 = 326,
			KP7 = 327,
			KP8 = 328,
			KP9 = 329,
			KPDecimal = 330,
			KPDivide = 331,
			KPMultiply = 332,
			KPSubtract = 333,
			KPAdd = 334,
			KPEnter = 335,
			KPEqual = 336,

			LeftShift = 340,
			LeftControl = 341,
			LeftAlt = 342,
			LeftSuper = 343,
			RightShift = 344,
			RightControl = 345,
			RightAlt = 346,
			RightSuper = 347,
			Menu = 348
		};
	}
}

#define ED_KEY_SPACE           ::Endeavor::Key::Space
#define ED_KEY_APOSTROPHE      ::Endeavor::Key::Apostrophe    /* ' */
#define ED_KEY_COMMA           ::Endeavor::Key::Comma         /* , */
#define ED_KEY_MINUS           ::Endeavor::Key::Minus         /* - */
#define ED_KEY_PERIOD          ::Endeavor::Key::Period        /* . */
#define ED_KEY_SLASH           ::Endeavor::Key::Slash         /* / */
#define ED_KEY_0               ::Endeavor::Key::D0
#define ED_KEY_1               ::Endeavor::Key::D1
#define ED_KEY_2               ::Endeavor::Key::D2
#define ED_KEY_3               ::Endeavor::Key::D3
#define ED_KEY_4               ::Endeavor::Key::D4
#define ED_KEY_5               ::Endeavor::Key::D5
#define ED_KEY_6               ::Endeavor::Key::D6
#define ED_KEY_7               ::Endeavor::Key::D7
#define ED_KEY_8               ::Endeavor::Key::D8
#define ED_KEY_9               ::Endeavor::Key::D9
#define ED_KEY_SEMICOLON       ::Endeavor::Key::Semicolon     /* ; */
#define ED_KEY_EQUAL           ::Endeavor::Key::Equal         /* = */
#define ED_KEY_A               ::Endeavor::Key::A
#define ED_KEY_B               ::Endeavor::Key::B
#define ED_KEY_C               ::Endeavor::Key::C
#define ED_KEY_D               ::Endeavor::Key::D
#define ED_KEY_E               ::Endeavor::Key::E
#define ED_KEY_F               ::Endeavor::Key::F
#define ED_KEY_G               ::Endeavor::Key::G
#define ED_KEY_H               ::Endeavor::Key::H
#define ED_KEY_I               ::Endeavor::Key::I
#define ED_KEY_J               ::Endeavor::Key::J
#define ED_KEY_K               ::Endeavor::Key::K
#define ED_KEY_L               ::Endeavor::Key::L
#define ED_KEY_M               ::Endeavor::Key::M
#define ED_KEY_N               ::Endeavor::Key::N
#define ED_KEY_O               ::Endeavor::Key::O
#define ED_KEY_P               ::Endeavor::Key::P
#define ED_KEY_Q               ::Endeavor::Key::Q
#define ED_KEY_R               ::Endeavor::Key::R
#define ED_KEY_S               ::Endeavor::Key::S
#define ED_KEY_T               ::Endeavor::Key::T
#define ED_KEY_U               ::Endeavor::Key::U
#define ED_KEY_V               ::Endeavor::Key::V
#define ED_KEY_W               ::Endeavor::Key::W
#define ED_KEY_X               ::Endeavor::Key::X
#define ED_KEY_Y               ::Endeavor::Key::Y
#define ED_KEY_Z               ::Endeavor::Key::Z
#define ED_KEY_LEFT_BRACKET    ::Endeavor::Key::LeftBracket   /* [ */
#define ED_KEY_BACKSLASH       ::Endeavor::Key::Backslash     /* \ */
#define ED_KEY_RIGHT_BRACKET   ::Endeavor::Key::RightBracket  /* ] */
#define ED_KEY_GRAVE_ACCENT    ::Endeavor::Key::GraveAccent   /* ` */
#define ED_KEY_WORLD_1         ::Endeavor::Key::World1        /* non-US #1 */
#define ED_KEY_WORLD_2         ::Endeavor::Key::World2        /* non-US #2 */

#define ED_KEY_ESCAPE          ::Endeavor::Key::Escape
#define ED_KEY_ENTER           ::Endeavor::Key::Enter
#define ED_KEY_TAB             ::Endeavor::Key::Tab
#define ED_KEY_BACKSPACE       ::Endeavor::Key::Backspace
#define ED_KEY_INSERT          ::Endeavor::Key::Insert
#define ED_KEY_DELETE          ::Endeavor::Key::Delete
#define ED_KEY_RIGHT           ::Endeavor::Key::Right
#define ED_KEY_LEFT            ::Endeavor::Key::Left
#define ED_KEY_DOWN            ::Endeavor::Key::Down
#define ED_KEY_UP              ::Endeavor::Key::Up
#define ED_KEY_PAGE_UP         ::Endeavor::Key::PageUp
#define ED_KEY_PAGE_DOWN       ::Endeavor::Key::PageDown
#define ED_KEY_HOME            ::Endeavor::Key::Home
#define ED_KEY_END             ::Endeavor::Key::End
#define ED_KEY_CAPS_LOCK       ::Endeavor::Key::CapsLock
#define ED_KEY_SCROLL_LOCK     ::Endeavor::Key::ScrollLock
#define ED_KEY_NUM_LOCK        ::Endeavor::Key::NumLock
#define ED_KEY_PRINT_SCREEN    ::Endeavor::Key::PrintScreen
#define ED_KEY_PAUSE           ::Endeavor::Key::Pause
#define ED_KEY_F1              ::Endeavor::Key::F1
#define ED_KEY_F2              ::Endeavor::Key::F2
#define ED_KEY_F3              ::Endeavor::Key::F3
#define ED_KEY_F4              ::Endeavor::Key::F4
#define ED_KEY_F5              ::Endeavor::Key::F5
#define ED_KEY_F6              ::Endeavor::Key::F6
#define ED_KEY_F7              ::Endeavor::Key::F7
#define ED_KEY_F8              ::Endeavor::Key::F8
#define ED_KEY_F9              ::Endeavor::Key::F9
#define ED_KEY_F10             ::Endeavor::Key::F10
#define ED_KEY_F11             ::Endeavor::Key::F11
#define ED_KEY_F12             ::Endeavor::Key::F12
#define ED_KEY_F13             ::Endeavor::Key::F13
#define ED_KEY_F14             ::Endeavor::Key::F14
#define ED_KEY_F15             ::Endeavor::Key::F15
#define ED_KEY_F16             ::Endeavor::Key::F16
#define ED_KEY_F17             ::Endeavor::Key::F17
#define ED_KEY_F18             ::Endeavor::Key::F18
#define ED_KEY_F19             ::Endeavor::Key::F19
#define ED_KEY_F20             ::Endeavor::Key::F20
#define ED_KEY_F21             ::Endeavor::Key::F21
#define ED_KEY_F22             ::Endeavor::Key::F22
#define ED_KEY_F23             ::Endeavor::Key::F23
#define ED_KEY_F24             ::Endeavor::Key::F24
#define ED_KEY_F25             ::Endeavor::Key::F25

/* Keypad */
#define ED_KEY_KP_0            ::Endeavor::Key::KP0
#define ED_KEY_KP_1            ::Endeavor::Key::KP1
#define ED_KEY_KP_2            ::Endeavor::Key::KP2
#define ED_KEY_KP_3            ::Endeavor::Key::KP3
#define ED_KEY_KP_4            ::Endeavor::Key::KP4
#define ED_KEY_KP_5            ::Endeavor::Key::KP5
#define ED_KEY_KP_6            ::Endeavor::Key::KP6
#define ED_KEY_KP_7            ::Endeavor::Key::KP7
#define ED_KEY_KP_8            ::Endeavor::Key::KP8
#define ED_KEY_KP_9            ::Endeavor::Key::KP9
#define ED_KEY_KP_DECIMAL      ::Endeavor::Key::KPDecimal
#define ED_KEY_KP_DIVIDE       ::Endeavor::Key::KPDivide
#define ED_KEY_KP_MULTIPLY     ::Endeavor::Key::KPMultiply
#define ED_KEY_KP_SUBTRACT     ::Endeavor::Key::KPSubtract
#define ED_KEY_KP_ADD          ::Endeavor::Key::KPAdd
#define ED_KEY_KP_ENTER        ::Endeavor::Key::KPEnter
#define ED_KEY_KP_EQUAL        ::Endeavor::Key::KPEqual

#define ED_KEY_LEFT_SHIFT      ::Endeavor::Key::LeftShift
#define ED_KEY_LEFT_CONTROL    ::Endeavor::Key::LeftControl
#define ED_KEY_LEFT_ALT        ::Endeavor::Key::LeftAlt
#define ED_KEY_LEFT_SUPER      ::Endeavor::Key::LeftSuper
#define ED_KEY_RIGHT_SHIFT     ::Endeavor::Key::RightShift
#define ED_KEY_RIGHT_CONTROL   ::Endeavor::Key::RightControl
#define ED_KEY_RIGHT_ALT       ::Endeavor::Key::RightAlt
#define ED_KEY_RIGHT_SUPER     ::Endeavor::Key::RightSuper
#define ED_KEY_MENU            ::Endeavor::Key::Menu