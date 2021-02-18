#include "AspirantApplication.h"
#include "MSetUIState.h"
#include "MEvent.h"
namespace aspirant
{
	const std::string CONFIG_FILE = "config/application.json";

	AspirantApplication::AspirantApplication()
		: tggd::common::Application(CONFIG_FILE)
		, uiState(UIState::MainMenu)
	{

	}

	bool AspirantApplication::IsRunning() const
	{
		return uiState!=UIState::Quit;
	}

	void AspirantApplication::Start()
	{

	}

	void AspirantApplication::Finish()
	{

	}

	bool AspirantApplication::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == MSetUIState::MSGID_SetUIState)
		{
			return OnSetUIState(static_cast<const MSetUIState*>(message)->GetState());
		}
		else if (message->GetId() == tggd::common::MEvent::MSGID_SdlEvent)
		{
			return OnSdlEvent(static_cast<const tggd::common::MEvent*>(message)->GetEvent());
		}
		return false;
	}

	bool AspirantApplication::OnSetUIState(const UIState& state)
	{
		uiState = state;
		return true;
	}

	bool AspirantApplication::OnSdlEvent(const SDL_Event& evt)
	{
		if (evt.type == SDL_QUIT)
		{
			uiState = UIState::Quit;
		}
		return true;
	}



	AspirantApplication application;
}