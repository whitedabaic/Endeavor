#pragma once

#include "Endeavor/Core/KeyCodes.h"
#include "Endeavor/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace Endeavor {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
