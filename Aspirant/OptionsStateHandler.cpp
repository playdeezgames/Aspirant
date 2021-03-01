#include "OptionsStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
#include "Utility.h"
#include <sstream>
namespace aspirant
{
	const std::string LAYOUT_NAME = "Options";
	const std::string OPTION_ITEM_COLOR_ACTIVE = "Cyan";//DUPLICATED
	const std::string OPTION_ITEM_COLOR_INACTIVE = "Gray";//DUPLICATED
	const std::string OPTION_ITEM_TOGGLE_MUTE_COLOR_STRING = "Options.Color.ToggleMute";
	const std::string OPTION_ITEM_SFX_VOLUME_COLOR_STRING = "Options.Color.SfxVolume";
	const std::string OPTION_ITEM_MUX_VOLUME_COLOR_STRING = "Options.Color.MuxVolume";
	const std::string OPTION_ITEM_BACK_COLOR_STRING = "Options.Color.Back";
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
		: UIStateMessageHandler(parent, currentState, UIState::OPTIONS)
		, layout(layoutManager.GetDescriptor(LAYOUT_NAME))
		, soundManager(soundManager)
		, optionsManager(optionsManager)
		, stringManager(stringManager)
		, menuItem(OptionsItem::BACK)
	{
	}


	bool OptionsStateHandler::OnUpdate()
	{

		//text for toggle mute
		if (soundManager.IsMuted())
		{
			stringManager.Set(TOGGLE_MUTE_STRING_NAME, UNMUTE);
		}
		else
		{
			stringManager.Set(TOGGLE_MUTE_STRING_NAME, MUTE);
		}
		std::stringstream ss;
		//text for sfx volume
		ss << "SFX Volume (" << tggd::common::Utility::ToPercentage(soundManager.GetSfxVolume(), MIX_MAX_VOLUME) << "%)";
		stringManager.Set(SFX_VOLUME_STRING_NAME, ss.str());

		//text for mux volume
		ss.str("");
		ss << "MUX Volume (" << tggd::common::Utility::ToPercentage(soundManager.GetMuxVolume(), MIX_MAX_VOLUME) << "%)";
		stringManager.Set(MUX_VOLUME_STRING_NAME, ss.str());

		UpdateMenuItemColorString(OPTION_ITEM_TOGGLE_MUTE_COLOR_STRING, OptionsItem::TOGGLE_MUTE);
		UpdateMenuItemColorString(OPTION_ITEM_SFX_VOLUME_COLOR_STRING, OptionsItem::SFX_VOLUME);
		UpdateMenuItemColorString(OPTION_ITEM_MUX_VOLUME_COLOR_STRING, OptionsItem::MUX_VOLUME);
		UpdateMenuItemColorString(OPTION_ITEM_BACK_COLOR_STRING, OptionsItem::BACK);

		return false;
	}

	bool OptionsStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		layout->Draw(renderer);
		return false;
	}

	bool OptionsStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::UP:
			PreviousItem();
			break;
		case Command::DOWN:
			NextItem();
			break;
		case Command::LEFT:
			DecreaseItem();
			break;
		case Command::RIGHT:
			IncreaseItem();
			break;
		case Command::GREEN:
			ActivateItem();
			break;
		case Command::RED:
		case Command::BACK:
		case Command::START:
			SetUIState(UIState::MAIN_MENU);
			break;
		}
		return true;
	}



	void OptionsStateHandler::UpdateMenuItemColorString(const std::string& stringName, const OptionsItem& optionsItem)
	{
		stringManager.Set
		(
			stringName,
			(optionsItem == menuItem) ? (OPTION_ITEM_COLOR_ACTIVE) :
			(OPTION_ITEM_COLOR_INACTIVE)
		);
	}


	bool OptionsStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		else if (message->GetId() == tggd::common::MUpdate::MSGID_Update)
		{
			return OnUpdate();
		}
		else if (message->GetId() == MCommand::MSGID_Command)
		{
			return OnCommand(static_cast<const MCommand*>(message)->GetCommand());
		}
		return false;
	}

	void OptionsStateHandler::NextItem()
	{
		switch (menuItem)
		{
		case OptionsItem::TOGGLE_MUTE:
			menuItem = OptionsItem::SFX_VOLUME;
			break;
		case OptionsItem::SFX_VOLUME:
			menuItem = OptionsItem::MUX_VOLUME;
			break;
		case OptionsItem::MUX_VOLUME:
			menuItem = OptionsItem::BACK;
			break;
		case OptionsItem::BACK:
			menuItem = OptionsItem::TOGGLE_MUTE;
			break;
		}
	}

	void OptionsStateHandler::PreviousItem()
	{
		switch (menuItem)
		{
		case OptionsItem::TOGGLE_MUTE:
			menuItem = OptionsItem::BACK;
			break;
		case OptionsItem::SFX_VOLUME:
			menuItem = OptionsItem::TOGGLE_MUTE;
			break;
		case OptionsItem::MUX_VOLUME:
			menuItem = OptionsItem::SFX_VOLUME;
			break;
		case OptionsItem::BACK:
			menuItem = OptionsItem::MUX_VOLUME;
			break;
		}
	}

	const int VOLUME_DELTA = 8;

	void OptionsStateHandler::IncreaseItem()
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

	void OptionsStateHandler::DecreaseItem()
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

	void OptionsStateHandler::ActivateItem()
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