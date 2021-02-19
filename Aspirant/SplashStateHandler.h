#pragma once
#include "UIStateMessageHandler.h"
#include "StaticImage.h"
#include "SpriteFont.h"
#include <SDL.h>
namespace aspirant
{
	class SplashStateHandler : public UIStateMessageHandler
	{
	private:
		tggd::common::StaticImage staticImage;
		const tggd::common::SpriteFont& spriteFont;
		bool OnDraw(SDL_Renderer*) const;
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		SplashStateHandler
		(
			MessageHandler*,
			const UIState&,
			const tggd::common::SpriteManager&,
			const tggd::common::ColorManager&,
			const tggd::common::SpriteFont&
		);
	};
}
