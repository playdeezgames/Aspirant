#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "CommonStateHandler.h"
namespace aspirant::navigationui
{
	class AboutStateHandler : public aspirant::commonui::CommonStateHandler
	{
	protected:
		bool OnCommand(const aspirant::commonui::Command&);
	public:
		AboutStateHandler
		(
			tggd::common::MessageHandler*,
			const aspirant::commonui::UIContext&
		);
	};
}
