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
	const std::string LAYOUT_NAME = "State.Options";
	const std::string MENU_ID = "Options";
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

	static void AdjustSfxVolume(int delta)
	{
		common::Sounds::SetSfxVolume(common::Sounds::GetSfxVolume() + delta);
		common::Sounds::PlaySound(SFX_SAMPLE_NAME);
		
		::Options::Save();
	}

	static void AdjustMuxVolume(int delta)
	{
		common::Sounds::SetMuxVolume(common::Sounds::GetMuxVolume() + delta);
		::Options::Save();
	}

	static OptionsItem GetCurrentItem()
	{
		return (OptionsItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME, MENU_ID).value();
	}

	static void ChangeItem(int delta)
	{
		switch (GetCurrentItem())
		{
		case OptionsItem::SFX_VOLUME:
			AdjustSfxVolume(delta);
			break;
		case OptionsItem::MUX_VOLUME:
			AdjustMuxVolume(delta);
			break;
		}
	}

	static void IncreaseItem()
	{
		ChangeItem(VOLUME_DELTA);
	}

	static void DecreaseItem()
	{
		ChangeItem(-VOLUME_DELTA);
	}

	static void ActivateItem()
	{
		switch (GetCurrentItem())
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
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
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

	static void UpdateMuteMenuItem()
	{
		if (common::Sounds::IsMuted())
		{
			::data::Strings::Set(TOGGLE_MUTE_STRING_NAME, UNMUTE);
		}
		else
		{
			::data::Strings::Set(TOGGLE_MUTE_STRING_NAME, MUTE);
		}
	}

	static void UpdateSfxMenuItem()
	{
		std::stringstream ss;
		ss << "SFX Volume (" << common::Utility::ToPercentage(common::Sounds::GetSfxVolume(), MIX_MAX_VOLUME) << "%)";
		::data::Strings::Set(SFX_VOLUME_STRING_NAME, ss.str());
	}

	static void UpdateMuxMenuItem()
	{
		std::stringstream ss;
		ss << "MUX Volume (" << common::Utility::ToPercentage(common::Sounds::GetMuxVolume(), MIX_MAX_VOLUME) << "%)";
		::data::Strings::Set(MUX_VOLUME_STRING_NAME, ss.str());
	}

	static void OnUpdate(const Uint32& ticks)
	{
		UpdateMuteMenuItem();
		UpdateSfxMenuItem();
		UpdateMuxMenuItem();
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::OPTIONS, OnCommand);
		::Application::SetRenderLayout(::UIState::OPTIONS, LAYOUT_NAME);
		::Application::SetUpdateHandler(::UIState::OPTIONS, OnUpdate);
	}
}