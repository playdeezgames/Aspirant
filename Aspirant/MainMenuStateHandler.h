#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
namespace aspirant
{
	class MainMenuStateHandler : public UIStateMessageHandler
	{
	private:
		bool OnDraw(SDL_Renderer*) const;
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		MainMenuStateHandler
		(
			MessageHandler*,
			const UIState&
		);
	};
}
