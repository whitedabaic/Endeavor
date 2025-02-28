#pragma once

#include <filesystem>

#include "Endeavor/Renderer/Texture.h"

namespace Endeavor {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();
		ContentBrowserPanel(const ContentBrowserPanel&) = default;
		ContentBrowserPanel& operator=(const ContentBrowserPanel&) = default;
		ContentBrowserPanel(ContentBrowserPanel&&) = default;
		ContentBrowserPanel& operator=(ContentBrowserPanel&&) = default;
		~ContentBrowserPanel() = default;
		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
	};
}
