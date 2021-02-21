#pragma once
#include "UIStateMessageHandler.h"
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
	class MainMenuStateHandler : public UIStateMessageHandler
	{
	private:
		tggd::common::StringManager& stringManager;
		MainMenuItem currentItem;
		const tggd::common::Layout* layout;
		bool OnDraw(SDL_Renderer*) const;
		bool OnUpdate();
		bool OnCommand(const Command&);
		void NextMenuItem();
		void PreviousMenuItem();
		void ActivateMenuItem();
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		MainMenuStateHandler
		(
			MessageHandler*,
			const UIState&,
			const tggd::common::LayoutManager&,
			tggd::common::StringManager&
		);
	};
}
