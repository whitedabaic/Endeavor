#include <Endeavor.h>
#include <Endeavor/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Endeavor {

	class EndeavorEditor : public Application
	{
	public:
		EndeavorEditor(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "EndeavorEditor";
		spec.CommandLineArgs = args;

		return new EndeavorEditor(spec);
	}
}
