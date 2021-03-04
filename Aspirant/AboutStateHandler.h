#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "CommonStateHandler.h"
namespace aspirant
{
	class AboutStateHandler : public CommonStateHandler
	{
	protected:
		bool OnCommand(const Command&);
	public:
		AboutStateHandler
		(
			MessageHandler*,
			const UIContext&
		);
	};
}
