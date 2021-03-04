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
		const UIContext& uiContext
	)
		: MenuStateHandler
			(
				parent, 
				UIState::START_GAME, 
				UIState::MAIN_MENU,
				LAYOUT_NAME,
				StartGameItem::BACK,
				uiContext
			)
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
			SetUIState(UIState::START_EDITOR);
			break;
		}
	}

}