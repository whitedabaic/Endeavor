#pragma once

#include "Endeavor/Core.h"
#include "Endeavor/Core/Timestep.h"
#include "Endeavor/Events/Event.h"

namespace Endeavor
{

	class ENDEAVOR_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}

