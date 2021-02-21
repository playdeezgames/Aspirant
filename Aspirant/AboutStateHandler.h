#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include <list>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
namespace aspirant
{
	class AboutStateHandler : public UIStateMessageHandler
	{
	private:
		const tggd::common::Layout* layout;
		bool OnDraw(SDL_Renderer*) const;
		bool OnCommand(const Command&);
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		AboutStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&
		);
	};
}
