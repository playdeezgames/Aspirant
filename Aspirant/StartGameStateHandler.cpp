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
		const aspirant::commonui::UIContext& uiContext
	)
		: MenuStateHandler
			(
				parent, 
				aspirant::commonui::UIState::START_GAME,
				aspirant::commonui::UIState::MAIN_MENU,
				LAYOUT_NAME,
				StartGameItem::BACK,
				uiContext
			)
	{
		AddMenuItem
		(
			StartGameItem::EDITOR,
			aspirant::commonui::MenuItemDescriptor<StartGameItem>(START_GAME_EDITOR_COLOR_NAME, StartGameItem::BACK, StartGameItem::BACK)
		);
		AddMenuItem
		(
			StartGameItem::BACK,
			aspirant::commonui::MenuItemDescriptor<StartGameItem>(START_GAME_BACK_COLOR_NAME, StartGameItem::EDITOR, StartGameItem::EDITOR)
		);
	}

	void StartGameStateHandler::ActivateItem(const StartGameItem& currentItem)
	{
		switch (currentItem)
		{
		case StartGameItem::BACK:
			SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			break;
		case StartGameItem::EDITOR:
			SetUIState(aspirant::commonui::UIState::START_EDITOR);
			break;
		}
	}

}