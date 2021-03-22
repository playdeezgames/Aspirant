#include "Aspirant.State.About.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
namespace aspirant::state::About
{
	const std::string LAYOUT_NAME = "About";

	static void OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::GREEN:
		case aspirant::commonui::Command::RED:
		case aspirant::commonui::Command::BACK:
		case aspirant::commonui::Command::START:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::ABOUT, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::ABOUT, OnDraw);
	}
}
