#pragma once

#include "Endeavor/Core/Layer.h"

#include "Endeavor/Events/ApplicationEvent.h"
#include "Endeavor/Events/KeyEvent.h"
#include "Endeavor/Events/MouseEvent.h"

namespace Endeavor
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemColors();
	private:
		bool m_BlockEvents = true;
	};
}
