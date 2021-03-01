#pragma once
#include "UIStateMessageHandler.h"
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
	class StartGameStateHandler : public UIStateMessageHandler
	{
	private:
		tggd::common::StringManager& stringManager;
		StartGameItem currentItem;
		const tggd::common::Layout* layout;
		bool OnDraw(SDL_Renderer*) const;
		bool OnCommand(const Command&);
		void UpdateMenuItemColorString(const std::string&, const StartGameItem&);
		bool OnUpdate();
		void NextMenuItem();
		void PreviousMenuItem();
		void ActivateMenuItem();
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		StartGameStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&,
			tggd::common::StringManager&
		);
	};
}
