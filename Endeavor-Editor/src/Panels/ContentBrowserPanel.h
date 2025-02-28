#pragma once

#include <filesystem>

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
	};
}
