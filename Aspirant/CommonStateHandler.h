#pragma once
#include "UIStateMessageHandler.h"
#include "Layout.h"
#include <SDL.h>
#include "Command.h"
namespace aspirant
{
	class CommonStateHandler : public UIStateMessageHandler
	{
	private:
		std::string layoutName;
		bool OnDraw(SDL_Renderer*) const;
	protected:
		virtual bool OnCommand(const Command&) = 0;
		virtual bool OnUpdate(int) { return false; }
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		CommonStateHandler
		(
			MessageHandler*,
			const UIState&,
			const std::string&,
			const UIContext&
		);
	};
}
