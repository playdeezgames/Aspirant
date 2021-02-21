#include "ConfirmQuitStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MCommand.h"
#include "MSetUIState.h"
namespace aspirant
{
	const std::string MENU_ITEM_COLOR_ACTIVE = "Cyan";//DUPLICATED
	const std::string MENU_ITEM_COLOR_INACTIVE = "Gray";//DUPLICATED
	const std::string MENU_ITEM_NO_COLOR_STRING = "ConfirmQuit.Color.No";
	const std::string MENU_ITEM_YES_COLOR_STRING = "ConfirmQuit.Color.Yes";
	const std::string LAYOUT_NAME = "ConfirmQuit";

	bool ConfirmQuitStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		SDL_RenderClear(renderer);
		layout->Draw(renderer);
		return true;
	}

	void ConfirmQuitStateHandler::UpdateMenuItemColorString(const std::string& stringName, const ConfirmQuitItem& menuItem)
	{
		stringManager.Set
		(
			stringName,
			(currentItem == menuItem) ? (MENU_ITEM_COLOR_ACTIVE) :
			(MENU_ITEM_COLOR_INACTIVE)
		);
	}


	bool ConfirmQuitStateHandler::OnUpdate()
	{
		UpdateMenuItemColorString(MENU_ITEM_NO_COLOR_STRING, ConfirmQuitItem::NO);
		UpdateMenuItemColorString(MENU_ITEM_YES_COLOR_STRING, ConfirmQuitItem::YES);
		return true;
	}


	bool ConfirmQuitStateHandler::OnMessage(const tggd::common::MGeneric* message)
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


	ConfirmQuitStateHandler::ConfirmQuitStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::CONFIRM_QUIT)
		, layout(layoutManager.GetDescriptor(LAYOUT_NAME))
		, stringManager(stringManager)
		, currentItem(ConfirmQuitItem::NO)
	{

	}

	bool ConfirmQuitStateHandler::OnCommand(const Command& command)
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

	void ConfirmQuitStateHandler::NextMenuItem()
	{
		currentItem = (currentItem == ConfirmQuitItem::NO) ? (ConfirmQuitItem::YES) : (ConfirmQuitItem::NO);
	}

	void ConfirmQuitStateHandler::PreviousMenuItem()
	{
		//DOES THE SAME THING!
		NextMenuItem();
	}

	void ConfirmQuitStateHandler::ActivateMenuItem()
	{
		switch (currentItem)
		{
		case ConfirmQuitItem::NO:
			Handle(MSetUIState(UIState::MAIN_MENU));
			return;
		case ConfirmQuitItem::YES:
			Handle(MSetUIState(UIState::QUIT));
			return;
		}
	}

}