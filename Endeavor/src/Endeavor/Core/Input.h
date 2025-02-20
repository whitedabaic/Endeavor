#pragma once

#include "Endeavor/Core/Base.h"
#include "Endeavor/Core/KeyCodes.h"
#include "Endeavor/Core/MouseCodes.h"

namespace Endeavor {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}