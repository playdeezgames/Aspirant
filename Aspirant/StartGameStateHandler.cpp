#include "StartGameStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MSetUIState.h"
#include "MUpdate.h"
namespace aspirant
{

	const std::string START_GAME_ITEM_COLOR_ACTIVE = "Cyan";//DUPLICATED
	const std::string START_GAME_COLOR_INACTIVE = "Gray";//DUPLICATED
	const std::string START_GAME_EDITOR_COLOR_STRING = "StartGame.Color.Editor";
	const std::string START_GAME_BACK_COLOR_STRING = "StartGame.Color.Back";
	const std::string LAYOUT_NAME = "StartGame";

	bool StartGameStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		layout->Draw(renderer);
		return false;
	}

	bool StartGameStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::RED:
		case Command::BACK:
			Handle(MSetUIState(UIState::MAIN_MENU));
			break;
		case Command::GREEN:
			ActivateMenuItem();
			break;
		case Command::UP:
			PreviousMenuItem();
			break;
		case Command::DOWN:
			NextMenuItem();
			break;
		}
		return true;
	}

	bool StartGameStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		else if (message->GetId() == MCommand::MSGID_Command)
		{
			return OnCommand(static_cast<const MCommand*>(message)->GetCommand());
		}
		else if (message->GetId() == tggd::common::MUpdate::MSGID_Update)
		{
			return OnUpdate();
		}
		return false;

	}

	bool StartGameStateHandler::OnUpdate()
	{
		UpdateMenuItemColorString(START_GAME_EDITOR_COLOR_STRING, StartGameItem::EDITOR);
		UpdateMenuItemColorString(START_GAME_BACK_COLOR_STRING, StartGameItem::BACK);
		return false;
	}

	StartGameStateHandler::StartGameStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::START_GAME)
		, layout(layoutManager.GetDescriptor(LAYOUT_NAME))
		, currentItem(StartGameItem::BACK)
		, stringManager(stringManager)
	{

	}

	void StartGameStateHandler::UpdateMenuItemColorString(const std::string& stringName, const StartGameItem& menuItem)
	{
		stringManager.Set
		(
			stringName,
			(currentItem == menuItem) ? (START_GAME_ITEM_COLOR_ACTIVE) :
			(START_GAME_COLOR_INACTIVE)
		);
	}

	void StartGameStateHandler::NextMenuItem()
	{
		switch (currentItem)
		{
		case StartGameItem::EDITOR:
			currentItem = StartGameItem::BACK;
			break;
		case StartGameItem::BACK:
			currentItem = StartGameItem::EDITOR;
			break;
		}
	}

	void StartGameStateHandler::PreviousMenuItem()
	{
		switch (currentItem)
		{
		case StartGameItem::EDITOR:
			currentItem = StartGameItem::BACK;
			break;
		case StartGameItem::BACK:
			currentItem = StartGameItem::EDITOR;
			break;
		}
	}

	void StartGameStateHandler::ActivateMenuItem()
	{
		switch (currentItem)
		{
		case StartGameItem::BACK:
			Handle(MSetUIState(UIState::MAIN_MENU));
			break;
		case StartGameItem::EDITOR:
			//TODO: go to select scenario to edit screen
			break;
		}
	}

}