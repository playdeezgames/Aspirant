#include "State.MainMenu.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "MenuItem.h"
#include <map>
#include "Data.Strings.h"
namespace state::MainMenu
{
	const std::string LAYOUT_NAME = "State.MainMenu";
	const std::string ITCH_URL_STRING = "ItchURL";
	const std::string MENU_ITEM_START_COLOR_NAME = "MainMenu.Color.Start";
	const std::string MENU_ITEM_ABOUT_COLOR_NAME = "MainMenu.Color.About";
	const std::string MENU_ITEM_OPTIONS_COLOR_NAME = "MainMenu.Color.Options";
	const std::string MENU_ITEM_QUIT_COLOR_NAME = "MainMenu.Color.Quit";

	enum class MainMenuItem
	{
		START,
		ABOUT,
		OPTIONS,
		QUIT
	};

	static MainMenuItem current = MainMenuItem::START;
	static std::map<MainMenuItem, ::MenuItem<MainMenuItem>> items = 
	{
		{MainMenuItem::START, ::MenuItem<MainMenuItem>
		(
			MENU_ITEM_START_COLOR_NAME,
			MainMenuItem::QUIT,
			MainMenuItem::ABOUT
		)},
		{MainMenuItem::ABOUT, ::MenuItem<MainMenuItem>
			(
				MENU_ITEM_ABOUT_COLOR_NAME,
				MainMenuItem::START,
				MainMenuItem::OPTIONS
		)},
		{MainMenuItem::OPTIONS, ::MenuItem<MainMenuItem>
			(
				MENU_ITEM_OPTIONS_COLOR_NAME,
				MainMenuItem::ABOUT,
				MainMenuItem::QUIT
		)},
		{MainMenuItem::QUIT, ::MenuItem<MainMenuItem>
			(
				MENU_ITEM_QUIT_COLOR_NAME,
				MainMenuItem::OPTIONS,
				MainMenuItem::START
		)}
	};

	static void ActivateItem()
	{
		switch (current)
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
			MenuItem<MainMenuItem>::Previous(current, items);
			break;
		case ::Command::DOWN:
			MenuItem<MainMenuItem>::Next(current, items);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::CONFIRM_QUIT);
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
		MenuItem<MainMenuItem>::Update(items, current);
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::MAIN_MENU, OnCommand);
		::Application::SetRenderLayout(::UIState::MAIN_MENU, LAYOUT_NAME);
		::Application::SetUpdateHandler(::UIState::MAIN_MENU, OnUpdate);
	}
}
