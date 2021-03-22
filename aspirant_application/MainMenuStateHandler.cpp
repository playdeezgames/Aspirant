#include "MainMenuStateHandler.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "MenuItemDescriptor.h"
#include <map>
#include "StringManager.h"
namespace aspirant::navigationui::MainMenuStateHandler
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
	static std::map<MainMenuItem, aspirant::commonui::MenuItemDescriptor<MainMenuItem>> items;

	static void ActivateItem()
	{
		switch (current)
		{
		case MainMenuItem::START:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::START_GAME);
			return;
		case MainMenuItem::OPTIONS:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::OPTIONS);
			return;
		case MainMenuItem::ABOUT:
			SDL_SetClipboardText(tggd::data::StringManager::Get(ITCH_URL_STRING).c_str());
			aspirant::Application::SetUIState(aspirant::commonui::UIState::ABOUT);
			return;
		case MainMenuItem::QUIT:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::CONFIRM_QUIT);
			return;
		}
	}

	static void OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case aspirant::commonui::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case aspirant::commonui::Command::GREEN:
			ActivateItem();
			break;
		case aspirant::commonui::Command::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::CONFIRM_QUIT);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		for (auto& item : items)
		{
			tggd::data::StringManager::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::MAIN_MENU, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::MAIN_MENU, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::MAIN_MENU, OnUpdate);
		items[MainMenuItem::START] = aspirant::commonui::MenuItemDescriptor<MainMenuItem>
		(
			MENU_ITEM_START_COLOR_NAME,
			MainMenuItem::QUIT,
			MainMenuItem::ABOUT
		);
		items[MainMenuItem::ABOUT] = aspirant::commonui::MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_ABOUT_COLOR_NAME,
				MainMenuItem::START,
				MainMenuItem::OPTIONS
		);
		items[MainMenuItem::OPTIONS] = aspirant::commonui::MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_OPTIONS_COLOR_NAME,
				MainMenuItem::ABOUT,
				MainMenuItem::QUIT
		);
		items[MainMenuItem::QUIT] = aspirant::commonui::MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_QUIT_COLOR_NAME,
				MainMenuItem::OPTIONS,
				MainMenuItem::START
		);
	}
}
