#include "MainMenuStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MCommand.h"
#include "MSetUIState.h"
namespace aspirant
{
	const std::string MENU_ITEM_COLOR_ACTIVE = "Cyan";//DUPLICATED
	const std::string MENU_ITEM_COLOR_INACTIVE = "Gray";//DUPLICATED
	const std::string MENU_ITEM_START_COLOR_STRING = "MainMenu.Color.Start";
	const std::string MENU_ITEM_ABOUT_COLOR_STRING = "MainMenu.Color.About";
	const std::string MENU_ITEM_OPTIONS_COLOR_STRING = "MainMenu.Color.Options";
	const std::string MENU_ITEM_QUIT_COLOR_STRING = "MainMenu.Color.Quit";
	const std::string LAYOUT_NAME = "MainMenu";
	const std::string ITCH_URL_STRING = "ItchURL";

	bool MainMenuStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		SDL_RenderClear(renderer);
		layout->Draw(renderer);
		return true;
	}

	void MainMenuStateHandler::UpdateMenuItemColorString(const std::string& stringName, const MainMenuItem& menuItem)
	{
		stringManager.Set
		(
			stringName, 
			(currentItem == menuItem) ? (MENU_ITEM_COLOR_ACTIVE) : 
			(MENU_ITEM_COLOR_INACTIVE)
		);
	}


	bool MainMenuStateHandler::OnUpdate()
	{
		UpdateMenuItemColorString(MENU_ITEM_START_COLOR_STRING, MainMenuItem::START);
		UpdateMenuItemColorString(MENU_ITEM_ABOUT_COLOR_STRING, MainMenuItem::ABOUT);
		UpdateMenuItemColorString(MENU_ITEM_OPTIONS_COLOR_STRING, MainMenuItem::OPTIONS);
		UpdateMenuItemColorString(MENU_ITEM_QUIT_COLOR_STRING, MainMenuItem::QUIT);
		return true;
	}


	bool MainMenuStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		else if (message->GetId() == tggd::common::MUpdate::MSGID_Update)
		{
			return OnUpdate();
		}
		else if (message->GetId() == MCommand::MSGID_Command)
		{
			return OnCommand(static_cast<const MCommand*>(message)->GetCommand());
		}
		return false;
	}


	MainMenuStateHandler::MainMenuStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::MAIN_MENU)
		, layout(layoutManager.GetDescriptor(LAYOUT_NAME))
		, stringManager(stringManager)
		, currentItem(MainMenuItem::START)
	{

	}

	bool MainMenuStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::UP:
			PreviousMenuItem();
			break;
		case Command::DOWN:
			NextMenuItem();
			break;
		case Command::GREEN:
		case Command::START:
			ActivateMenuItem();
			break;
		}
		return true;
	}

	void MainMenuStateHandler::NextMenuItem()
	{
		switch (currentItem)
		{
		case MainMenuItem::START:
			currentItem = MainMenuItem::ABOUT;
			break;
		case MainMenuItem::ABOUT:
			currentItem = MainMenuItem::OPTIONS;
			break;
		case MainMenuItem::OPTIONS:
			currentItem = MainMenuItem::QUIT;
			break;
		case MainMenuItem::QUIT:
			currentItem = MainMenuItem::START;
			break;
		}
	}

	void MainMenuStateHandler::PreviousMenuItem()
	{
		switch (currentItem)
		{
		case MainMenuItem::START:
			currentItem = MainMenuItem::QUIT;
			break;
		case MainMenuItem::ABOUT:
			currentItem = MainMenuItem::START;
			break;
		case MainMenuItem::OPTIONS:
			currentItem = MainMenuItem::ABOUT;
			break;
		case MainMenuItem::QUIT:
			currentItem = MainMenuItem::OPTIONS;
			break;
		}
	}

	void MainMenuStateHandler::ActivateMenuItem()
	{
		switch (currentItem)
		{
		case MainMenuItem::ABOUT:
			SDL_SetClipboardText(stringManager.Get(ITCH_URL_STRING).c_str());
			Handle(MSetUIState(UIState::ABOUT));
			return;
		case MainMenuItem::QUIT:
			Handle(MSetUIState(UIState::CONFIRM_QUIT));
			return;
		}
	}

}