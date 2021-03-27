#include "State.About.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
namespace state::About
{
	const std::string LAYOUT_NAME = "About";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Draw(renderer, LAYOUT_NAME);
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::ABOUT, OnCommand);
		::Application::SetRenderHandler(::UIState::ABOUT, OnDraw);
	}
}
