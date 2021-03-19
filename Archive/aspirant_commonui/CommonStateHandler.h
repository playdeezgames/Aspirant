#pragma once
#include "UIStateMessageHandler.h"
#include "Layout.h"
#include <SDL.h>
#include "Command.h"
namespace aspirant::commonui
{
	class CommonStateHandler : public UIStateMessageHandler
	{
		CommonStateHandler() = delete;
		CommonStateHandler(const CommonStateHandler&) = delete;
		CommonStateHandler(CommonStateHandler&&) = delete;
		CommonStateHandler& operator=(const CommonStateHandler&) = delete;
		CommonStateHandler& operator=(CommonStateHandler&&) = delete;
	private:
		std::string layoutName;
	protected:
		virtual bool OnDraw(SDL_Renderer*) const;
		virtual bool OnCommand(const Command&) = 0;
		virtual bool OnUpdate(int) { return false; }
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		CommonStateHandler
		(
			tggd::common::MessageHandler*,
			const UIState&,
			const std::string&,
			const UIContext&
		);
	};
}