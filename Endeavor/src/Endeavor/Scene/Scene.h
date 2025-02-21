#pragma once

#include "entt.hpp"
#include "Endeavor/Core/Timestep.h"

namespace Endeavor {

	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(Timestep ts);
	private:
		entt::registry m_Registry;
	};
}