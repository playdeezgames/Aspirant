#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include <list>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
namespace aspirant
{
	class SplashStateHandler : public UIStateMessageHandler
	{
	private:
		const tggd::common::Layout* layout;
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
			tggd::common::LayoutManager&,
			const UIContext&
		);
	};
}
