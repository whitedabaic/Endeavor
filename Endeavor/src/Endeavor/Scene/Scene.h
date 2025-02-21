#pragma once

#include "entt.hpp"

namespace Endeavor {

	class Scene
	{
	public:
		Scene();
		~Scene();
	private:
		entt::registry m_Registry;
	};
}