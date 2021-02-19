#pragma once
#include "UIStateMessageHandler.h"
#include "SpriteManager.h"
#include <SDL.h>
namespace aspirant
{
	class SplashStateHandler : public UIStateMessageHandler
	{
	private:
		const tggd::common::SpriteManager& spriteManager;
		bool OnDraw(SDL_Renderer*) const;
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		SplashStateHandler
		(
			MessageHandler* parent, 
			const UIState& currentState,
			const tggd::common::SpriteManager& spriteManager
		)
			: UIStateMessageHandler(parent, currentState, UIState::Splash)
			, spriteManager(spriteManager)
		{

		}
	};
}
