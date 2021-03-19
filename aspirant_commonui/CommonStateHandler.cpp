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
		if (tggd::common::MRender::Is(message))
		{
			return OnDraw(tggd::common::MRender::From(message)->GetRenderer());
		}
		else if (MCommand::Is(message))
		{
			return OnCommand(MCommand::From(message)->GetCommand());
		}
		else if (tggd::common::MUpdate::Is(message))
		{
			return OnUpdate(tggd::common::MUpdate::From(message)->GetMilliseconds());
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