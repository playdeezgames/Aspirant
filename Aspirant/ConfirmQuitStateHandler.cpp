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
		const aspirant::commonui::UIContext& uiContext
	)
		: aspirant::commonui::MenuStateHandler<ConfirmQuitItem>
		(
			parent, 
			aspirant::commonui::UIState::CONFIRM_QUIT,
			aspirant::commonui::UIState::MAIN_MENU,
			LAYOUT_NAME, 
			ConfirmQuitItem::NO,
			uiContext
		)
	{
		AddMenuItem
		(
			ConfirmQuitItem::YES,
			aspirant::commonui::MenuItemDescriptor<ConfirmQuitItem>(CONFIRM_ITEM_YES_COLOR_NAME, ConfirmQuitItem::NO, ConfirmQuitItem::NO)
		);
		AddMenuItem
		(
			ConfirmQuitItem::NO,
			aspirant::commonui::MenuItemDescriptor<ConfirmQuitItem>(CONFIRM_ITEM_NO_COLOR_NAME, ConfirmQuitItem::YES, ConfirmQuitItem::YES)
		);
	}

	void ConfirmQuitStateHandler::ActivateItem(const ConfirmQuitItem& currentItem)
	{
		switch (currentItem)
		{
		case ConfirmQuitItem::NO:
			SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			return;
		case ConfirmQuitItem::YES:
			SetUIState(aspirant::commonui::UIState::QUIT);
			return;
		}
	}
}