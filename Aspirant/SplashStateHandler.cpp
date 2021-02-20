#include "SplashStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MSetUIState.h"
#include "MCommand.h"
#include "Utility.h"
namespace aspirant
{
	const int TICKS_LEFT = 3000;

	SplashStateHandler::SplashStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const tggd::common::SpriteManager& spriteManager,
		const tggd::common::ColorManager& colorManager,
		const tggd::common::FontManager& fontManager,
		tggd::common::FinishManager& finishManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::Splash)
		, ticksLeft(TICKS_LEFT)
		, layout(finishManager, spriteManager, colorManager, fontManager,tggd::common::Utility::LoadJSON("assets/layouts/splash.json"))
	{
	}

	bool SplashStateHandler::OnUpdate(unsigned int milliseconds)
	{
		ticksLeft = (ticksLeft > milliseconds) ? (ticksLeft - milliseconds) : (0);
		if (ticksLeft == 0)
		{
			Handle(MSetUIState(UIState::MainMenu));
			ticksLeft = TICKS_LEFT;
		}
		return true;
	}

	bool SplashStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		layout.Draw(renderer);
		return false;
	}

	bool SplashStateHandler::OnCommand(const Command& command)
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
		else if (message->GetId() == MCommand::MSGID_Command)
		{
			return OnCommand(static_cast<const MCommand*>(message)->GetCommand());
		}
		return false;
	}
}