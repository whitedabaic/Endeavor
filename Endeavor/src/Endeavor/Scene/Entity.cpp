#include "edpch.h"
#include "Entity.h"

namespace Endeavor {
	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}
}