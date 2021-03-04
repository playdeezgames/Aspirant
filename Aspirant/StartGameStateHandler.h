#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "StringManager.h"
namespace aspirant
{
	enum class StartGameItem
	{
		EDITOR,
		BACK
	};
	class StartGameStateHandler : public MenuStateHandler<StartGameItem>
	{
	protected:
		void ActivateItem(const StartGameItem&);
	public:
		StartGameStateHandler
		(
			MessageHandler*,
			const UIContext&
		);
	};
}
