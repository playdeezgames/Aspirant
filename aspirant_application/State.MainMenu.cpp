#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include <map>
#include "Data.Strings.h"
namespace state::MainMenu
{
	const std::string LAYOUT_NAME = "State.MainMenu";
	const std::string MENU_ID = "Main";
	const std::string ITCH_URL_STRING = "ItchURL";

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
			::Application::SetUIState(::UIState::START_GAME);
			return;
		case MainMenuItem::OPTIONS:
			::Application::SetUIState(::UIState::OPTIONS);
			return;
		case MainMenuItem::ABOUT:
			SDL_SetClipboardText(::data::Strings::Get(ITCH_URL_STRING).c_str());
			::Application::SetUIState(::UIState::ABOUT);
			return;
		case MainMenuItem::QUIT:
			::Application::SetUIState(::UIState::CONFIRM_QUIT);
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
			::Application::SetUIState(::UIState::CONFIRM_QUIT);
			break;
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::MAIN_MENU, OnCommand);
		::Application::SetRenderLayout(::UIState::MAIN_MENU, LAYOUT_NAME);
	}
}
