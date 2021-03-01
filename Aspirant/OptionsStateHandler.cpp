#include "OptionsStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
#include "Utility.h"
#include <sstream>
namespace aspirant
{
	const std::string LAYOUT_NAME = "Options";
	const std::string OPTION_ITEM_TOGGLE_MUTE_COLOR_NAME = "Options.Color.ToggleMute";
	const std::string OPTION_ITEM_SFX_VOLUME_COLOR_NAME = "Options.Color.SfxVolume";
	const std::string OPTION_ITEM_MUX_VOLUME_COLOR_NAME = "Options.Color.MuxVolume";
	const std::string OPTION_ITEM_BACK_COLOR_NAME = "Options.Color.Back";

	const std::string TOGGLE_MUTE_STRING_NAME = "Options.Text.ToggleMute";
	const std::string SFX_VOLUME_STRING_NAME = "Options.Text.SfxVolume";
	const std::string MUX_VOLUME_STRING_NAME = "Options.Text.MuxVolume";
	const std::string MUTE = "Mute";
	const std::string UNMUTE = "Unmute";

	OptionsStateHandler::OptionsStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		tggd::common::LayoutManager& layoutManager,
		tggd::common::SoundManager& soundManager,
		OptionsManager& optionsManager,
		tggd::common::StringManager& stringManager
	)
		: MenuStateHandler
			(
				parent, 
				currentState, 
				UIState::OPTIONS, 
				UIState::MAIN_MENU,
				layoutManager.GetDescriptor(LAYOUT_NAME), 
				stringManager, 
				OptionsItem::BACK
			)
		, soundManager(soundManager)
		, optionsManager(optionsManager)
	{
		AddMenuItem
		(
			OptionsItem::TOGGLE_MUTE, 
			MenuItemDescriptor<OptionsItem>
			(
				OPTION_ITEM_TOGGLE_MUTE_COLOR_NAME, 
				OptionsItem::BACK, 
				OptionsItem::SFX_VOLUME
			)
		);
		AddMenuItem
		(
			OptionsItem::SFX_VOLUME,
			MenuItemDescriptor<OptionsItem>
			(
				OPTION_ITEM_SFX_VOLUME_COLOR_NAME,
				OptionsItem::TOGGLE_MUTE,
				OptionsItem::MUX_VOLUME
				)
		);
		AddMenuItem
		(
			OptionsItem::MUX_VOLUME,
			MenuItemDescriptor<OptionsItem>
			(
				OPTION_ITEM_MUX_VOLUME_COLOR_NAME,
				OptionsItem::SFX_VOLUME,
				OptionsItem::BACK
				)
		);
		AddMenuItem
		(
			OptionsItem::BACK,
			MenuItemDescriptor<OptionsItem>
			(
				OPTION_ITEM_BACK_COLOR_NAME,
				OptionsItem::MUX_VOLUME,
				OptionsItem::TOGGLE_MUTE
				)
		);
	}


	bool OptionsStateHandler::OnUpdate()
	{

		//text for toggle mute
		if (soundManager.IsMuted())
		{
			GetStringManager().Set(TOGGLE_MUTE_STRING_NAME, UNMUTE);
		}
		else
		{
			GetStringManager().Set(TOGGLE_MUTE_STRING_NAME, MUTE);
		}
		std::stringstream ss;
		//text for sfx volume
		ss << "SFX Volume (" << tggd::common::Utility::ToPercentage(soundManager.GetSfxVolume(), MIX_MAX_VOLUME) << "%)";
		GetStringManager().Set(SFX_VOLUME_STRING_NAME, ss.str());

		//text for mux volume
		ss.str("");
		ss << "MUX Volume (" << tggd::common::Utility::ToPercentage(soundManager.GetMuxVolume(), MIX_MAX_VOLUME) << "%)";
		GetStringManager().Set(MUX_VOLUME_STRING_NAME, ss.str());

		return MenuStateHandler::OnUpdate();
	}

	const int VOLUME_DELTA = 8;

	void OptionsStateHandler::IncreaseItem(const OptionsItem& menuItem)
	{
		switch (menuItem)
		{
		case OptionsItem::SFX_VOLUME:
			AdjustSfxVolume(VOLUME_DELTA);
			break;
		case OptionsItem::MUX_VOLUME:
			AdjustMuxVolume(VOLUME_DELTA);
			break;
		}
	}

	void OptionsStateHandler::DecreaseItem(const OptionsItem& menuItem)
	{
		switch (menuItem)
		{
		case OptionsItem::SFX_VOLUME:
			AdjustSfxVolume(-VOLUME_DELTA);
			break;
		case OptionsItem::MUX_VOLUME:
			AdjustMuxVolume(-VOLUME_DELTA);
			break;
		}
	}

	void OptionsStateHandler::ActivateItem(const OptionsItem& menuItem)
	{
		switch (menuItem)
		{
		case OptionsItem::TOGGLE_MUTE:
			soundManager.SetMuted(!soundManager.IsMuted());
			optionsManager.Save();
			break;
		case OptionsItem::BACK:
			SetUIState(UIState::MAIN_MENU);
			break;
		}
	}

	const std::string SFX_SAMPLE_NAME = "woohoo";

	void OptionsStateHandler::AdjustSfxVolume(int delta)
	{
		soundManager.SetSfxVolume(soundManager.GetSfxVolume() + delta);
		soundManager.PlaySound(SFX_SAMPLE_NAME);
		optionsManager.Save();
	}

	void OptionsStateHandler::AdjustMuxVolume(int delta)
	{
		soundManager.SetMuxVolume(soundManager.GetMuxVolume() + delta);//TODO: magic number
		optionsManager.Save();
	}

}