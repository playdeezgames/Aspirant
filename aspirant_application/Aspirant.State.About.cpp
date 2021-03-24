#include "Aspirant.State.About.h"
#include "Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
namespace aspirant::state::About
{
	const std::string LAYOUT_NAME = "About";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	void Start()
	{
		::Application::SetCommandHandler(aspirant::UIState::ABOUT, OnCommand);
		::Application::SetRenderHandler(aspirant::UIState::ABOUT, OnDraw);
	}
}
