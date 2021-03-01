#pragma once
#include "MenuStateHandler.h"
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
	class OptionsStateHandler : public MenuStateHandler<OptionsItem>
	{
	private:
		tggd::common::SoundManager& soundManager;
		OptionsManager& optionsManager;
		void AdjustSfxVolume(int);
		void AdjustMuxVolume(int);
	protected:
		void IncreaseItem(const OptionsItem&);
		void DecreaseItem(const OptionsItem&);
		void ActivateItem(const OptionsItem&);
		bool OnUpdate();
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
