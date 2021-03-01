#include "StartEditorStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
namespace aspirant
{

	const std::string START_EDITOR_NEW_COLOR_NAME = "StartEditor.Color.New";
	const std::string START_EDITOR_BACK_COLOR_NAME = "StartEditor.Color.Back";
	const std::string START_EDITOR_OPEN_COLOR_NAME = "StartEditor.Color.Open";
	const std::string LAYOUT_NAME = "StartEditor";

	StartEditorStateHandler::StartEditorStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager
	)
		: MenuStateHandler
		(
			parent,
			currentState,
			UIState::START_EDITOR,
			UIState::START_GAME,
			layoutManager.GetDescriptor(LAYOUT_NAME),
			stringManager,
			StartEditorItem::BACK
		)
	{
		AddMenuItem
		(
			StartEditorItem::NEW,
			MenuItemDescriptor<StartEditorItem>(START_EDITOR_NEW_COLOR_NAME, StartEditorItem::BACK, StartEditorItem::OPEN)
		);
		AddMenuItem
		(
			StartEditorItem::OPEN,
			MenuItemDescriptor<StartEditorItem>(START_EDITOR_OPEN_COLOR_NAME, StartEditorItem::NEW, StartEditorItem::BACK)
		);
		AddMenuItem
		(
			StartEditorItem::BACK,
			MenuItemDescriptor<StartEditorItem>(START_EDITOR_BACK_COLOR_NAME, StartEditorItem::OPEN, StartEditorItem::NEW)
		);
	}

	void StartEditorStateHandler::ActivateItem(const StartEditorItem& currentItem)
	{
		switch (currentItem)
		{
		case StartEditorItem::BACK:
			SetUIState(UIState::START_GAME);
			break;
		case StartEditorItem::NEW:
			//TODO
			break;
		}
	}

}