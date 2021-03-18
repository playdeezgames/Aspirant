#include "MainMenuStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MCommand.h"
namespace aspirant::navigationui
{
	const std::string LAYOUT_NAME = "MainMenu";
	const std::string ITCH_URL_STRING = "ItchURL";

	const std::string MENU_ITEM_START_COLOR_NAME = "MainMenu.Color.Start";
	const std::string MENU_ITEM_ABOUT_COLOR_NAME = "MainMenu.Color.About";
	const std::string MENU_ITEM_OPTIONS_COLOR_NAME = "MainMenu.Color.Options";
	const std::string MENU_ITEM_QUIT_COLOR_NAME = "MainMenu.Color.Quit";

	MainMenuStateHandler::MainMenuStateHandler
	(
		MessageHandler* parent,
		const aspirant::commonui::UIContext& uiContext
	)
		: MenuStateHandler
			(
				parent, 
				aspirant::commonui::UIState::MAIN_MENU,
				aspirant::commonui::UIState::CONFIRM_QUIT,
				LAYOUT_NAME, 
				MainMenuItem::START,
				uiContext
			)
	{
		AddMenuItem
		(
			MainMenuItem::START, 
			aspirant::commonui::MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_START_COLOR_NAME, 
				MainMenuItem::QUIT, 
				MainMenuItem::ABOUT
			)
		);
		AddMenuItem
		(
			MainMenuItem::ABOUT,
			aspirant::commonui::MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_ABOUT_COLOR_NAME,
				MainMenuItem::START,
				MainMenuItem::OPTIONS
			)
		);
		AddMenuItem
		(
			MainMenuItem::OPTIONS,
			aspirant::commonui::MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_OPTIONS_COLOR_NAME,
				MainMenuItem::ABOUT,
				MainMenuItem::QUIT
			)
		);
		AddMenuItem
		(
			MainMenuItem::QUIT,
			aspirant::commonui::MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_QUIT_COLOR_NAME,
				MainMenuItem::OPTIONS,
				MainMenuItem::START
			)
		);
	}

	void MainMenuStateHandler::ActivateItem(const MainMenuItem& currentItem)
	{
		switch (currentItem)
		{
		case MainMenuItem::START:
			SetUIState(aspirant::commonui::UIState::START_GAME);
			return;
		case MainMenuItem::OPTIONS:
			SetUIState(aspirant::commonui::UIState::OPTIONS);
			return;
		case MainMenuItem::ABOUT:
			SDL_SetClipboardText(GetStringManager()[ITCH_URL_STRING].c_str());
			SetUIState(aspirant::commonui::UIState::ABOUT);
			return;
		case MainMenuItem::QUIT:
			SetUIState(aspirant::commonui::UIState::CONFIRM_QUIT);
			return;
		}
	}

}