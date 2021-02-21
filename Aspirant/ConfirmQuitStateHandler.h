#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include "LayoutManager.h"
#include "StringManager.h"
#include "Command.h"
namespace aspirant
{
	enum class ConfirmQuitItem
	{
		NO,
		YES
	};
	class ConfirmQuitStateHandler : public UIStateMessageHandler
	{
	private:
		tggd::common::StringManager& stringManager;
		ConfirmQuitItem currentItem;
		const tggd::common::Layout* layout;
		bool OnDraw(SDL_Renderer*) const;
		bool OnUpdate();
		bool OnCommand(const Command&);
		void NextMenuItem();
		void PreviousMenuItem();
		void ActivateMenuItem();
		void UpdateMenuItemColorString(const std::string&, const ConfirmQuitItem&);
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		ConfirmQuitStateHandler
		(
			MessageHandler*,
			const UIState&,
			const tggd::common::LayoutManager&,
			tggd::common::StringManager&
		);
	};
}
