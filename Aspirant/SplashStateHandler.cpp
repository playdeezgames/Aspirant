#include "SplashStateHandler.h"
#include "MRender.h"
namespace aspirant
{
	const std::string SPRITE_NAME = "Splash";
	const std::string SPRITE_COLOR = "white";
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;

	SplashStateHandler::SplashStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const tggd::common::SpriteManager& spriteManager,
		const tggd::common::ColorManager& colorManager,
		const tggd::common::SpriteFont& spriteFont
	)
		: UIStateMessageHandler(parent, currentState, UIState::Splash)
		, spriteFont(spriteFont)
		, staticImage(spriteManager, colorManager, SPRITE_NAME, SPRITE_COLOR, tggd::common::XY<int>(SPRITE_X, SPRITE_Y))
	{
	}

	bool SplashStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		staticImage.Draw(renderer);
		spriteFont.WriteText(renderer, tggd::common::XY<int>(0, 0), "Hello, world!", "white");
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