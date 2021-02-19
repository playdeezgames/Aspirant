#include "SplashStateHandler.h"
#include "MRender.h"
namespace aspirant
{
	const std::string SPRITE_NAME = "Splash";
	const std::string SPRITE_COLOR = "White";
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;

	SplashStateHandler::SplashStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const tggd::common::SpriteManager& spriteManager,
		const tggd::common::ColorManager& colorManager,
		const tggd::common::FontManager& fontManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::Splash)
		, fontManager(fontManager)
		, staticImage(spriteManager, colorManager, SPRITE_NAME, SPRITE_COLOR, tggd::common::XY<int>(SPRITE_X, SPRITE_Y))
		, labels()
	{
		labels.push_back
		(
			tggd::common::Label
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
		labels.push_back
		(
			tggd::common::Label
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

	bool SplashStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		staticImage.Draw(renderer);
		for (auto label : labels)
		{
			label.Draw(renderer);
		}
		return false;
	}

	bool SplashStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		return false;
	}
}