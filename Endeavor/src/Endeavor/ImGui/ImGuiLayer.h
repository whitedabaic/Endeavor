#pragma once

#include "Endeavor/Core/Layer.h"

#include "Endeavor/Events/ApplicationEvent.h"
#include "Endeavor/Events/KeyEvent.h"
#include "Endeavor/Events/MouseEvent.h"

namespace Endeavor
{
	class ENDEAVOR_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}