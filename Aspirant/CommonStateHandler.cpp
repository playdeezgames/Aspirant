#include "CommonStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
namespace aspirant
{
	bool CommonStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		layout->Draw(renderer);
		return false;
	}

	bool CommonStateHandler::OnMessage(const tggd::common::MGeneric* message)
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
			return OnUpdate(static_cast<const tggd::common::MUpdate*>(message)->GetMilliseconds());
		}
		return false;
	}

	CommonStateHandler::CommonStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const UIState& filterState,
		const tggd::common::Layout* layout,
		const UIContext& uiContext
	)
		: UIStateMessageHandler(parent, currentState, filterState, uiContext)
		, layout(layout)
	{

	}

}