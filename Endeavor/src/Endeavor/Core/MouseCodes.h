#pragma once

namespace Endeavor
{
	using MouseCode = uint16_t;

	namespace Mouse
	{
		enum : MouseCode
		{
			// From glfw3.h
			Button0 = 0,
			Button1 = 1,
			Button2 = 2,
			Button3 = 3,
			Button4 = 4,
			Button5 = 5,
			Button6 = 6,
			Button7 = 7,

			ButtonLast = Button7,
			ButtonLeft = Button0,
			ButtonRight = Button1,
			ButtonMiddle = Button2
		};
	}
}

#define ED_MOUSE_BUTTON_0      ::Endeavor::Mouse::Button0
#define ED_MOUSE_BUTTON_1      ::Endeavor::Mouse::Button1
#define ED_MOUSE_BUTTON_2      ::Endeavor::Mouse::Button2
#define ED_MOUSE_BUTTON_3      ::Endeavor::Mouse::Button3
#define ED_MOUSE_BUTTON_4      ::Endeavor::Mouse::Button4
#define ED_MOUSE_BUTTON_5      ::Endeavor::Mouse::Button5
#define ED_MOUSE_BUTTON_6      ::Endeavor::Mouse::Button6
#define ED_MOUSE_BUTTON_7      ::Endeavor::Mouse::Button7
#define ED_MOUSE_BUTTON_LAST   ::Endeavor::Mouse::ButtonLast
#define ED_MOUSE_BUTTON_LEFT   ::Endeavor::Mouse::ButtonLeft
#define ED_MOUSE_BUTTON_RIGHT  ::Endeavor::Mouse::ButtonRight
#define ED_MOUSE_BUTTON_MIDDLE ::Endeavor::Mouse::ButtonMiddle