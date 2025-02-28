#include <Endeavor.h>
#include <Endeavor/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Endeavor {

	class EndeavorEditor : public Application
	{
	public:
		EndeavorEditor(ApplicationCommandLineArgs args)
			: Application("Endeavor Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~EndeavorEditor()
		{

		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new EndeavorEditor(args);
	}
}
