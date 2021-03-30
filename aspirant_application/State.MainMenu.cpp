#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include <map>
#include "Application.Command.h"
#include "Application.MouseButtonDown.h"
#include "Application.UIState.h"
namespace state::MainMenu
{
	const std::string LAYOUT_NAME = "State.MainMenu";
	const std::string MENU_ID = "Main";

	enum class MainMenuItem
	{
		START,
		ABOUT,
		OPTIONS,
		QUIT
	};

	static void ActivateItem()
	{
		switch ((MainMenuItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME, MENU_ID).value())
		{
		case MainMenuItem::START:
			::application::UIState::SetUIState(::UIState::START_GAME);
			return;
		case MainMenuItem::OPTIONS:
			::application::UIState::SetUIState(::UIState::OPTIONS);
			return;
		case MainMenuItem::ABOUT:
			SDL_SetClipboardText("https://thegrumpygamedev.itch.io/");
			::application::UIState::SetUIState(::UIState::ABOUT);
			return;
		case MainMenuItem::QUIT:
			::application::UIState::SetUIState(::UIState::CONFIRM_QUIT);
			return;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::application::UIState::SetUIState(::UIState::CONFIRM_QUIT);
			break;
		}
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::MAIN_MENU, OnCommand);
		::Application::SetRenderLayout(::UIState::MAIN_MENU, LAYOUT_NAME);
	}
}
