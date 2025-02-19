#include <Endeavor.h>
#include <Endeavor/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Endeavor {

	class EndeavorEditor : public Application
	{
	public:
		EndeavorEditor()
			: Application("Endeavor Editor")
		{
			PushLayer(new EditorLayer());
		}

		~EndeavorEditor()
		{

		}
	};

	Application* CreateApplication()
	{
		return new EndeavorEditor();
	}
}