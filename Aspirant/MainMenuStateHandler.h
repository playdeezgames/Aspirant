#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include "LayoutManager.h"
namespace aspirant
{
	class MainMenuStateHandler : public UIStateMessageHandler
	{
	private:
		const tggd::common::Layout* layout;
		bool OnDraw(SDL_Renderer*) const;
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		MainMenuStateHandler
		(
			MessageHandler*,
			const UIState&,
			const tggd::common::LayoutManager&
		);
	};
}
