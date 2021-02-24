#include "OptionsStateHandler.h"
#include "MRender.h"
#include "MSetUIState.h"
#include "MCommand.h"
#include "MUpdate.h"
#include "Utility.h"
#include <sstream>
namespace aspirant
{
	const std::string LAYOUT_NAME = "Options";

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

	const std::string TOGGLE_MUTE_STRING_NAME = "Options.Text.ToggleMute";
	const std::string SFX_VOLUME_STRING_NAME = "Options.Text.SfxVolume";
	const std::string MUX_VOLUME_STRING_NAME = "Options.Text.MuxVolume";
	const std::string MUTE = "Mute";
	const std::string UNMUTE = "Unmute";

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
		ss << "SFX Volume (" << soundManager.GetSfxVolume() << "%)";
		stringManager.Set(SFX_VOLUME_STRING_NAME, ss.str());

		//text for mux volume
		ss.str("");
		ss << "MUX Volume (" << soundManager.GetMuxVolume() << "%)";
		stringManager.Set(MUX_VOLUME_STRING_NAME, ss.str());
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
			Handle(MSetUIState(UIState::MAIN_MENU));
			break;
		}
		return true;
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
	}

	void OptionsStateHandler::PreviousItem()
	{

	}

	void OptionsStateHandler::IncreaseItem()
	{

	}

	void OptionsStateHandler::DecreaseItem()
	{

	}

	void OptionsStateHandler::ActivateItem()
	{

	}
}