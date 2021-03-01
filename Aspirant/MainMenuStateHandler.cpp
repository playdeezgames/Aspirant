#include "MainMenuStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MCommand.h"
namespace aspirant
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
		const UIState& currentState,
		const tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager
	)
		: MenuStateHandler
			(
				parent, 
				currentState, 
				UIState::MAIN_MENU, 
				UIState::CONFIRM_QUIT,
				layoutManager.GetDescriptor(LAYOUT_NAME), 
				stringManager, 
				MainMenuItem::START
			)
	{
		AddMenuItem
		(
			MainMenuItem::START, 
			MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_START_COLOR_NAME, 
				MainMenuItem::QUIT, 
				MainMenuItem::ABOUT
			)
		);
		AddMenuItem
		(
			MainMenuItem::ABOUT,
			MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_ABOUT_COLOR_NAME,
				MainMenuItem::START,
				MainMenuItem::OPTIONS
			)
		);
		AddMenuItem
		(
			MainMenuItem::OPTIONS,
			MenuItemDescriptor<MainMenuItem>
			(
				MENU_ITEM_OPTIONS_COLOR_NAME,
				MainMenuItem::ABOUT,
				MainMenuItem::QUIT
			)
		);
		AddMenuItem
		(
			MainMenuItem::QUIT,
			MenuItemDescriptor<MainMenuItem>
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
			SetUIState(UIState::START_GAME);
			return;
		case MainMenuItem::OPTIONS:
			SetUIState(UIState::OPTIONS);
			return;
		case MainMenuItem::ABOUT:
			SDL_SetClipboardText(GetStringManager().Get(ITCH_URL_STRING).c_str());
			SetUIState(UIState::ABOUT);
			return;
		case MainMenuItem::QUIT:
			SetUIState(UIState::CONFIRM_QUIT);
			return;
		}
	}

}