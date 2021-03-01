#include "AboutStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "Utility.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "About";

	AboutStateHandler::AboutStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		tggd::common::LayoutManager& layoutManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::ABOUT)
		, layout(layoutManager.GetDescriptor(LAYOUT_NAME))
	{
	}

	bool AboutStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		layout->Draw(renderer);
		return false;
	}

	bool AboutStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::GREEN:
		case Command::RED:
		case Command::BACK:
		case Command::START:
			SetUIState(UIState::MAIN_MENU);
			break;
		}
		return true;
	}


	bool AboutStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		else if (message->GetId() == MCommand::MSGID_Command)
		{
			return OnCommand(static_cast<const MCommand*>(message)->GetCommand());
		}
		return false;
	}
}