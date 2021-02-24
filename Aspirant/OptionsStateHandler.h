#pragma once
#include "UIStateMessageHandler.h"
#include <SDL.h>
#include <list>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "SoundManager.h"
#include "OptionsManager.h"
#include "StringManager.h"
namespace aspirant
{
	enum class OptionsItem
	{
		TOGGLE_MUTE,
		SFX_VOLUME,
		MUX_VOLUME,
		BACK
	};
	class OptionsStateHandler : public UIStateMessageHandler
	{
	private:
		const tggd::common::Layout* layout;
		tggd::common::SoundManager& soundManager;
		OptionsManager& optionsManager;
		tggd::common::StringManager& stringManager;
		OptionsItem menuItem;
		void NextItem();
		void PreviousItem();
		void IncreaseItem();
		void DecreaseItem();
		void ActivateItem();
		bool OnDraw(SDL_Renderer*) const;
		bool OnCommand(const Command&);
		bool OnUpdate();
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
	public:
		OptionsStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&,
			tggd::common::SoundManager&,
			OptionsManager&,
			tggd::common::StringManager&
		);
	};
}
