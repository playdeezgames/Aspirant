#pragma once
#include "UIStateMessageHandler.h"
#include "SpriteManager.h"
#include "SpriteFont.h"
#include <SDL.h>
namespace aspirant
{
	class SplashStateHandler : public UIStateMessageHandler
	{
	private:
		const tggd::common::SpriteManager& spriteManager;
		const tggd::common::SpriteFont& spriteFont;
		bool OnDraw(SDL_Renderer*) const;
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		SplashStateHandler
		(
			MessageHandler* parent,
			const UIState& currentState,
			const tggd::common::SpriteManager& spriteManager,
			const tggd::common::SpriteFont& spriteFont
		)
			: UIStateMessageHandler(parent, currentState, UIState::Splash)
			, spriteManager(spriteManager)
			, spriteFont(spriteFont)
			, labels()
		{
		}
	};
}
