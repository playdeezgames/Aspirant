#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "LayoutManager.h"
#include "StringManager.h"
#include "Command.h"
namespace aspirant
{
	enum class MainMenuItem
	{
		START,
		ABOUT,
		OPTIONS,
		QUIT
	};
	class MainMenuStateHandler : public MenuStateHandler<MainMenuItem>
	{
	protected:
		void ActivateItem(const MainMenuItem&);
	public:
		MainMenuStateHandler
		(
			MessageHandler*,
			tggd::common::StringManager&,
			const UIContext&
		);
	};
}
