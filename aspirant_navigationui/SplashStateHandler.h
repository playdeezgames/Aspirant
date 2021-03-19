#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include <list>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
namespace aspirant::navigationui
{
	class SplashStateHandler : public aspirant::commonui::UIStateMessageHandler
	{
		SplashStateHandler() = delete;
		SplashStateHandler(const SplashStateHandler&) = delete;
		SplashStateHandler(SplashStateHandler&&) = delete;
		SplashStateHandler& operator=(const SplashStateHandler&) = delete;
		SplashStateHandler& operator=(SplashStateHandler&&) = delete;
	private:
		bool OnDraw(SDL_Renderer*) const;
		bool OnUpdate(unsigned int);
		bool OnCommand(const aspirant::commonui::Command&);
		unsigned int ticksLeft;
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		SplashStateHandler
		(
			tggd::common::MessageHandler*,
			const aspirant::commonui::UIContext&
		);
	};
}
