#include "MainMenuStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MCommand.h"
namespace aspirant
{
	bool MainMenuStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		SDL_RenderClear(renderer);
		layout->Draw(renderer);
		return true;
	}

	bool MainMenuStateHandler::OnUpdate()
	{
		//TODO: magic strings
		stringManager.Set("MainMenu.Color.Start", (currentItem == MainMenuItem::START) ? ("Cyan") : ("Gray"));
		stringManager.Set("MainMenu.Color.About", (currentItem == MainMenuItem::ABOUT) ? ("Cyan") : ("Gray"));
		stringManager.Set("MainMenu.Color.Options", (currentItem == MainMenuItem::OPTIONS) ? ("Cyan") : ("Gray"));
		stringManager.Set("MainMenu.Color.Quit", (currentItem == MainMenuItem::QUIT) ? ("Cyan") : ("Gray"));
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

	const std::string LAYOUT_NAME = "MainMenu";

	MainMenuStateHandler::MainMenuStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::MainMenu)
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

	}

}