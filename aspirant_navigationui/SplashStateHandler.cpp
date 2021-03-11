#include "SplashStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MCommand.h"
#include "Utility.h"
namespace aspirant::navigationui
{
	const int TICKS_LEFT = 3000;
	const std::string LAYOUT_NAME = "Splash";

	SplashStateHandler::SplashStateHandler
	(
		MessageHandler* parent,
		const aspirant::commonui::UIContext& uiContext
	)
		: UIStateMessageHandler(parent, aspirant::commonui::UIState::SPLASH, uiContext)
		, ticksLeft(TICKS_LEFT)
	{
	}

	bool SplashStateHandler::OnUpdate(unsigned int milliseconds)
	{
		ticksLeft = (ticksLeft > milliseconds) ? (ticksLeft - milliseconds) : (0);
		if (ticksLeft == 0)
		{
			SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			ticksLeft = TICKS_LEFT;
		}
		return true;
	}

	bool SplashStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		GetUIContext().GetLayoutManager().GetDescriptor(LAYOUT_NAME)->Draw(renderer);
		return false;
	}

	bool SplashStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		ticksLeft = 0;
		return true;
	}


	bool SplashStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		else if (message->GetId() == tggd::common::MUpdate::MSGID_Update)
		{
			return OnUpdate(static_cast<const tggd::common::MUpdate*>(message)->GetMilliseconds());
		}
		else if (message->GetId() == aspirant::commonui::MCommand::MSGID_Command)
		{
			return OnCommand(static_cast<const aspirant::commonui::MCommand*>(message)->GetCommand());
		}
		return false;
	}
}