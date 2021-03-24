#include "Aspirant.State.MainMenu.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "MenuItem.h"
#include <map>
#include "Data.Strings.h"
namespace aspirant::state::MainMenu
{
	const std::string LAYOUT_NAME = "MainMenu";
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
	static std::map<MainMenuItem, ::MenuItem<MainMenuItem>> items;

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
			current = items[current].GetPreviousMenuItem();
			break;
		case ::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::CONFIRM_QUIT);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::MAIN_MENU, OnCommand);
		::Application::SetRenderHandler(::UIState::MAIN_MENU, OnDraw);
		::Application::SetUpdateHandler(::UIState::MAIN_MENU, OnUpdate);
		items[MainMenuItem::START] = ::MenuItem<MainMenuItem>
		(
			MENU_ITEM_START_COLOR_NAME,
			MainMenuItem::QUIT,
			MainMenuItem::ABOUT
		);
		items[MainMenuItem::ABOUT] = ::MenuItem<MainMenuItem>
			(
				MENU_ITEM_ABOUT_COLOR_NAME,
				MainMenuItem::START,
				MainMenuItem::OPTIONS
		);
		items[MainMenuItem::OPTIONS] = ::MenuItem<MainMenuItem>
			(
				MENU_ITEM_OPTIONS_COLOR_NAME,
				MainMenuItem::ABOUT,
				MainMenuItem::QUIT
		);
		items[MainMenuItem::QUIT] = ::MenuItem<MainMenuItem>
			(
				MENU_ITEM_QUIT_COLOR_NAME,
				MainMenuItem::OPTIONS,
				MainMenuItem::START
		);
	}
}
