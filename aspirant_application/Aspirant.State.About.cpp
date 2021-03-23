#include "Aspirant.State.About.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
namespace aspirant::state::About
{
	const std::string LAYOUT_NAME = "About";

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::UIState::ABOUT, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::ABOUT, OnDraw);
	}
}
