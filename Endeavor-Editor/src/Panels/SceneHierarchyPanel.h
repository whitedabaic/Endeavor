#pragma once

#include "Endeavor/Core/Base.h"
#include "Endeavor/Core/Log.h"
#include "Endeavor/Scene/Scene.h"
#include "Endeavor/Scene/Entity.h"

namespace Endeavor {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponent(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}
