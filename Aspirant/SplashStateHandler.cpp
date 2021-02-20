#include "SplashStateHandler.h"
#include "MRender.h"
#include "MUpdate.h"
#include "MSetUIState.h"
#include "MCommand.h"
namespace aspirant
{
	const std::string SPRITE_NAME = "Splash";
	const std::string SPRITE_COLOR = "White";
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;
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
		, layout(finishManager)
	{
		layout.Add
		(
			new tggd::common::StaticImage
			(
				spriteManager, 
				colorManager, 
				SPRITE_NAME, 
				SPRITE_COLOR, 
				tggd::common::XY<int>
				(
					SPRITE_X, 
					SPRITE_Y
				)
			)
		);
		layout.Add
		(
			new tggd::common::StaticText
			(
				tggd::common::XY<int>(320-20*8,180-8),
				"Aspirant of SPLORR!!",
				fontManager,
				"default",
				"Cyan",
				true,
				tggd::common::XY<int>(2,2),
				"Black"
			)
		);
		layout.Add
		(
			new tggd::common::StaticText
			(
				tggd::common::XY<int>(320 - 32 * 8, 360 - 18),
				"A Production of TheGrumpyGameDev",
				fontManager,
				"default",
				"DarkGray",
				true,
				tggd::common::XY<int>(2, 2),
				"Black"
			)
		);
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