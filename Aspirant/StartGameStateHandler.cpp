#include "StartGameStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
namespace aspirant
{

	const std::string START_GAME_EDITOR_COLOR_NAME = "StartGame.Color.Editor";
	const std::string START_GAME_BACK_COLOR_NAME = "StartGame.Color.Back";
	const std::string LAYOUT_NAME = "StartGame";

	StartGameStateHandler::StartGameStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager
	)
		: MenuStateHandler(parent, currentState, UIState::START_GAME, layoutManager.GetDescriptor(LAYOUT_NAME), stringManager, StartGameItem::BACK)
	{
		AddMenuItem
		(
			StartGameItem::EDITOR,
			MenuItemDescriptor<StartGameItem>(START_GAME_EDITOR_COLOR_NAME, StartGameItem::BACK, StartGameItem::BACK)
		);
		AddMenuItem
		(
			StartGameItem::BACK,
			MenuItemDescriptor<StartGameItem>(START_GAME_BACK_COLOR_NAME, StartGameItem::EDITOR, StartGameItem::EDITOR)
		);
	}

	void StartGameStateHandler::ActivateItem(const StartGameItem& currentItem)
	{
		switch (currentItem)
		{
		case StartGameItem::BACK:
			SetUIState(UIState::MAIN_MENU);
			break;
		case StartGameItem::EDITOR:
			//TODO: go to select scenario to edit screen
			break;
		}
	}

}