#pragma once
#include "UIStateMessageHandler.h"
#include "StaticImage.h"
#include "SpriteFont.h"
#include <SDL.h>
#include "StaticText.h"
#include <list>
#include "Command.h"
#include "Layout.h"
namespace aspirant
{
	class SplashStateHandler : public UIStateMessageHandler
	{
	private:
		tggd::common::Layout layout;
		bool OnDraw(SDL_Renderer*) const;
		bool OnUpdate(unsigned int);
		bool OnCommand(const Command&);
		unsigned int ticksLeft;
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		SplashStateHandler
		(
			MessageHandler*,
			const UIState&,
			const tggd::common::SpriteManager&,
			const tggd::common::ColorManager&,
			const tggd::common::FontManager&,
			tggd::common::FinishManager&
		);
	};
}
