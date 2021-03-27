#include "State.Options.h"
#include "Application.h"
#include "UIState.h"
#include <map>
#include "MenuItem.h"
#include "Graphics.Layouts.h"
#include "Data.Strings.h"
#include "Common.Sounds.h"
#include "Options.h"
#include <sstream>
#include "Common.Utility.h"
namespace state::Options
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

	const std::string SFX_SAMPLE_NAME = "woohoo";

	enum class OptionsItem
	{
		TOGGLE_MUTE,
		SFX_VOLUME,
		MUX_VOLUME,
		BACK
	};

	const int VOLUME_DELTA = 8;
	static OptionsItem current = OptionsItem::BACK;
	static std::map<OptionsItem, ::MenuItem<OptionsItem>> items =
	{
		{OptionsItem::TOGGLE_MUTE,
			::MenuItem<OptionsItem>
			(
				OPTION_ITEM_TOGGLE_MUTE_COLOR_NAME,
				OptionsItem::BACK,
				OptionsItem::SFX_VOLUME
		)},
		{OptionsItem::SFX_VOLUME,
			::MenuItem<OptionsItem>
			(
				OPTION_ITEM_SFX_VOLUME_COLOR_NAME,
				OptionsItem::TOGGLE_MUTE,
				OptionsItem::MUX_VOLUME
		)},
		{OptionsItem::MUX_VOLUME,
			::MenuItem<OptionsItem>
			(
				OPTION_ITEM_MUX_VOLUME_COLOR_NAME,
				OptionsItem::SFX_VOLUME,
				OptionsItem::BACK
		)},
		{OptionsItem::BACK,
			::MenuItem<OptionsItem>
			(
				OPTION_ITEM_BACK_COLOR_NAME,
				OptionsItem::MUX_VOLUME,
				OptionsItem::TOGGLE_MUTE
		)}
	};


	static void AdjustSfxVolume(int delta)
	{
		common::Sounds::SetSfxVolume(common::Sounds::GetSfxVolume() + delta);
		common::Sounds::PlaySound(SFX_SAMPLE_NAME);
		
		::Options::Save();
	}

	static void AdjustMuxVolume(int delta)
	{
		common::Sounds::SetMuxVolume(common::Sounds::GetMuxVolume() + delta);//TODO: magic number
		::Options::Save();
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
			::Options::Save();
			break;
		case OptionsItem::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			MenuItem<OptionsItem>::Previous(current, items);
			break;
		case ::Command::DOWN:
			MenuItem<OptionsItem>::Next(current, items);
			break;
		case ::Command::LEFT:
			DecreaseItem();
			break;
		case ::Command::RIGHT:
			IncreaseItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Draw(renderer, LAYOUT_NAME);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		MenuItem<OptionsItem>::Update(items, current);

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
		::Application::SetCommandHandler(::UIState::OPTIONS, OnCommand);
		::Application::SetRenderHandler(::UIState::OPTIONS, OnDraw);
		::Application::SetUpdateHandler(::UIState::OPTIONS, OnUpdate);
	}
}
