#include "CommonStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
namespace aspirant::commonui
{
	bool CommonStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		GetUIContext().GetLayoutManager().GetDescriptor(layoutName)->Draw(renderer);
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
		const UIState& filterState,
		const std::string& layoutName,
		const UIContext& uiContext
	)
		: UIStateMessageHandler(parent, filterState, uiContext)
		, layoutName(layoutName)
	{

	}

}