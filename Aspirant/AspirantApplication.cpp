#include "AspirantApplication.h"
#include "MSetUIState.h"
#include "MEvent.h"
#include "SplashStateHandler.h"
namespace aspirant
{
	const std::string APPLICATION_CONFIG_FILE = "config/application.json";
	const std::string TEXTURE_CONFIG_FILE = "config/textures.json";
	const std::string SPRITE_CONFIG_FILE = "config/sprites.json";

	AspirantApplication::AspirantApplication()
		: tggd::common::Application(APPLICATION_CONFIG_FILE)
		, finishManager()
		, textureManager(finishManager)
		, spriteManager(finishManager)
		, uiState(UIState::Splash)
	{

	}

	bool AspirantApplication::IsRunning() const
	{
		return uiState!=UIState::Quit;
	}

	void AspirantApplication::Start(SDL_Renderer* renderer)
	{
		textureManager.Start(renderer, TEXTURE_CONFIG_FILE);
		spriteManager.Start(textureManager, SPRITE_CONFIG_FILE);

		new SplashStateHandler(this, uiState, spriteManager);
	}

	void AspirantApplication::Finish()
	{
		finishManager.Finish();
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