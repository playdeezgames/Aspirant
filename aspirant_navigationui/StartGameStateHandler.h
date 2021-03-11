#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "StringManager.h"
namespace aspirant::navigationui
{
	enum class StartGameItem
	{
		EDITOR,
		BACK
	};
	class StartGameStateHandler : public aspirant::commonui::MenuStateHandler<StartGameItem>
	{
	protected:
		void ActivateItem(const StartGameItem&);
	public:
		StartGameStateHandler
		(
			tggd::common::MessageHandler*,
			const aspirant::commonui::UIContext&
		);
	};
}
