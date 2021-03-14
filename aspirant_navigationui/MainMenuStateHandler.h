#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "LayoutManager.h"
#include "StringManager.h"
#include "Command.h"
namespace aspirant::navigationui
{
	enum class MainMenuItem
	{
		START,
		ABOUT,
		OPTIONS,
		QUIT
	};
	class MainMenuStateHandler : public aspirant::commonui::MenuStateHandler<MainMenuItem>
	{
	protected:
		void ActivateItem(const MainMenuItem&);
	public:
		MainMenuStateHandler
		(
			MessageHandler*,
			const aspirant::commonui::UIContext&
		);
	};
}