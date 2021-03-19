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
		if (tggd::common::MRender::Is(message))
		{
			return OnDraw(tggd::common::MRender::From(message)->GetRenderer());
		}
		else if (tggd::common::MUpdate::Is(message))
		{
			return OnUpdate(tggd::common::MUpdate::From(message)->GetMilliseconds());
		}
		else if (aspirant::commonui::MCommand::Is(message))
		{
			return OnCommand(aspirant::commonui::MCommand::From(message)->GetCommand());
		}
		return false;
	}
}