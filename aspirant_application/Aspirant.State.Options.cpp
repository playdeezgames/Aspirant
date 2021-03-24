#include "Aspirant.State.Options.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include <map>
#include "Aspirant.MenuItem.h"
#include "Graphics.Layouts.h"
#include "Data.Strings.h"
#include "Common.Sounds.h"
#include "Aspirant.Options.h"
#include <sstream>
#include "Common.Utility.h"
namespace aspirant::state::Options
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

	enum class OptionsItem
	{
		TOGGLE_MUTE,
		SFX_VOLUME,
		MUX_VOLUME,
		BACK
	};

	const int VOLUME_DELTA = 8;
	static OptionsItem current = OptionsItem::BACK;

	const std::string SFX_SAMPLE_NAME = "woohoo";

	static void AdjustSfxVolume(int delta)
	{
		common::Sounds::SetSfxVolume(common::Sounds::GetSfxVolume() + delta);
		common::Sounds::PlaySound(SFX_SAMPLE_NAME);
		
		aspirant::Options::Save();
	}

	static void AdjustMuxVolume(int delta)
	{
		common::Sounds::SetMuxVolume(common::Sounds::GetMuxVolume() + delta);//TODO: magic number
		aspirant::Options::Save();
	}


	static void IncreaseItem()
	{
		switch (current)
		{
		case OptionsItem::SFX_VOLUME:
			AdjustSfxVolume(VOLUME_DELTA);
			break;
		case OptionsItem::MUX_VOLUME:
			AdjustMuxVolume(VOLUME_DELTA);
			break;
		}
	}

	static void DecreaseItem()
	{
		switch (current)
		{
		case OptionsItem::SFX_VOLUME:
			AdjustSfxVolume(-VOLUME_DELTA);
			break;
		case OptionsItem::MUX_VOLUME:
			AdjustMuxVolume(-VOLUME_DELTA);
			break;
		}
	}

	static void ActivateItem()
	{
		switch (current)
		{
		case OptionsItem::TOGGLE_MUTE:
			common::Sounds::SetMuted(!common::Sounds::IsMuted());
			aspirant::Options::Save();
			break;
		case OptionsItem::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			break;
		}
	}

	static std::map<OptionsItem, aspirant::MenuItem<OptionsItem>> items;

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case aspirant::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case aspirant::Command::LEFT:
			DecreaseItem();
			break;
		case aspirant::Command::RIGHT:
			IncreaseItem();
			break;
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			break;
		case aspirant::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}

		if (common::Sounds::IsMuted())
		{
			::data::Strings::Set(TOGGLE_MUTE_STRING_NAME, UNMUTE);
		}
		else
		{
			::data::Strings::Set(TOGGLE_MUTE_STRING_NAME, MUTE);
		}
		std::stringstream ss;
		//text for sfx volume
		ss << "SFX Volume (" << common::Utility::ToPercentage(common::Sounds::GetSfxVolume(), MIX_MAX_VOLUME) << "%)";
		::data::Strings::Set(SFX_VOLUME_STRING_NAME, ss.str());

		//text for mux volume
		ss.str("");
		ss << "MUX Volume (" << common::Utility::ToPercentage(common::Sounds::GetMuxVolume(), MIX_MAX_VOLUME) << "%)";
		::data::Strings::Set(MUX_VOLUME_STRING_NAME, ss.str());

	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::UIState::OPTIONS, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::OPTIONS, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::OPTIONS, OnUpdate);
		items[OptionsItem::TOGGLE_MUTE]=
			aspirant::MenuItem<OptionsItem>
			(
				OPTION_ITEM_TOGGLE_MUTE_COLOR_NAME,
				OptionsItem::BACK,
				OptionsItem::SFX_VOLUME
		);
		items[OptionsItem::SFX_VOLUME]=
			aspirant::MenuItem<OptionsItem>
			(
				OPTION_ITEM_SFX_VOLUME_COLOR_NAME,
				OptionsItem::TOGGLE_MUTE,
				OptionsItem::MUX_VOLUME
		);
		items[OptionsItem::MUX_VOLUME]=
			aspirant::MenuItem<OptionsItem>
			(
				OPTION_ITEM_MUX_VOLUME_COLOR_NAME,
				OptionsItem::SFX_VOLUME,
				OptionsItem::BACK
		);
		items[OptionsItem::BACK]=
			aspirant::MenuItem<OptionsItem>
			(
				OPTION_ITEM_BACK_COLOR_NAME,
				OptionsItem::MUX_VOLUME,
				OptionsItem::TOGGLE_MUTE
		);
	}
}
