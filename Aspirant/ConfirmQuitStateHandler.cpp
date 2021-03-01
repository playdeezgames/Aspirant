#include "ConfirmQuitStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MCommand.h"
namespace aspirant
{
	const std::string CONFIRM_ITEM_NO_COLOR_NAME = "ConfirmQuit.Color.No";
	const std::string CONFIRM_ITEM_YES_COLOR_NAME = "ConfirmQuit.Color.Yes";
	const std::string LAYOUT_NAME = "ConfirmQuit";

	ConfirmQuitStateHandler::ConfirmQuitStateHandler
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
			UIState::CONFIRM_QUIT, 
			layoutManager.GetDescriptor(LAYOUT_NAME), 
			stringManager,
			ConfirmQuitItem::NO
		)
	{
		AddMenuItem
		(
			ConfirmQuitItem::YES,
			MenuItemDescriptor<ConfirmQuitItem>(CONFIRM_ITEM_YES_COLOR_NAME, ConfirmQuitItem::NO, ConfirmQuitItem::NO)
		);
		AddMenuItem
		(
			ConfirmQuitItem::NO,
			MenuItemDescriptor<ConfirmQuitItem>(CONFIRM_ITEM_NO_COLOR_NAME, ConfirmQuitItem::YES, ConfirmQuitItem::YES)
		);
	}

	void ConfirmQuitStateHandler::ActivateItem(const ConfirmQuitItem& currentItem)
	{
		switch (currentItem)
		{
		case ConfirmQuitItem::NO:
			SetUIState(UIState::MAIN_MENU);
			return;
		case ConfirmQuitItem::YES:
			SetUIState(UIState::QUIT);
			return;
		}
	}
}