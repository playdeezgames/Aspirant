#include "AspirantApplication.h"
#include "MSetUIState.h"
#include "MEvent.h"
#include "SplashStateHandler.h"
#include "MainMenuStateHandler.h"
#include "AboutStateHandler.h"
#include "ConfirmQuitStateHandler.h"
#include "OptionsStateHandler.h"
#include "StartGameStateHandler.h"
#include "StartEditorStateHandler.h"
#include "EditScenarioSelectorStateHandler.h"
#include "Utility.h"
namespace aspirant
{
	const std::string APPLICATION_CONFIG_FILE = "config/ui/application.json";
	const std::string TEXTURE_CONFIG_FILE = "config/graphics/textures.json";
	const std::string SPRITE_CONFIG_FILE = "config/graphics/sprites.json";
	const std::string COLOR_CONFIG_FILE = "config/graphics/colors.json";
	const std::string FONTS_CONFIG_FILE = "config/graphics/fonts.json";
	const std::string LAYOUTS_CONFIG_FILE = "config/ui/layouts.json";
	const std::string STRINGS_CONFIG_FILE = "config/data/strings.json";
	const std::string INTS_CONFIG_FILE = "config/data/ints.json";
	const std::string FLAGS_CONFIG_FILE = "config/data/flags.json";
	const std::string OPTIONS_CONFIG_FILE = "config/options.json";
	const std::string SFX_CONFIG_FILE = "config/audio/sfx.json";
	const std::string MUX_CONFIG_FILE = "config/audio/mux.json";
	const std::string DESCRIPTORS_CONFIG_FILE = "config/game/descriptors.json";
	const std::string SCENARIOS_CONFIG_FILE = "scenarios/scenarios.json";

	AspirantApplication::AspirantApplication()
		: tggd::common::Application(APPLICATION_CONFIG_FILE)
		, finishManager()
		, textureManager(finishManager)
		, spriteManager(finishManager)
		, colorManager(finishManager)
		, fontManager(finishManager, spriteManager, colorManager)
		, stringManager()
		, intManager()
		, flagManager()
		, soundManager(finishManager)
		, optionsManager(soundManager, OPTIONS_CONFIG_FILE)
		, layoutManager(finishManager, spriteManager, colorManager, fontManager, stringManager, intManager, flagManager)
		, uiState(UIState::SPLASH)
		, descriptors(finishManager)
		, scenarios(finishManager, SCENARIOS_CONFIG_FILE)
		, editorContext()
	{

	}

	bool AspirantApplication::IsRunning() const
	{
		return uiState!=UIState::QUIT;
	}

	void AspirantApplication::Start(SDL_Renderer* renderer)
	{
		stringManager.Start(STRINGS_CONFIG_FILE);
		intManager.Start(INTS_CONFIG_FILE);
		flagManager.Start(FLAGS_CONFIG_FILE);
		colorManager.Start(COLOR_CONFIG_FILE);
		textureManager.Start(renderer, TEXTURE_CONFIG_FILE);
		spriteManager.Start(textureManager, SPRITE_CONFIG_FILE);
		fontManager.Start(FONTS_CONFIG_FILE);
		layoutManager.Start(LAYOUTS_CONFIG_FILE);
		soundManager.Start(SFX_CONFIG_FILE, MUX_CONFIG_FILE);
		optionsManager.Start();
		descriptors.Start(DESCRIPTORS_CONFIG_FILE);
		scenarios.Load();

		new SplashStateHandler(this, uiState, layoutManager);
		new MainMenuStateHandler(this, uiState, layoutManager, stringManager);
		new AboutStateHandler(this, uiState, layoutManager);
		new ConfirmQuitStateHandler(this, uiState, layoutManager, stringManager);
		new OptionsStateHandler(this, uiState, layoutManager, soundManager, optionsManager, stringManager);
		new StartGameStateHandler(this, uiState, layoutManager, stringManager);
		new StartEditorStateHandler(this, uiState, layoutManager, stringManager, scenarios, editorContext);
		new EditScenarioSelectorStateHandler(this, uiState, layoutManager);
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

	bool AspirantApplication::OnKeyDown(const SDL_KeyboardEvent& keyEvent)
	{
		switch (keyEvent.keysym.sym)
		{
		case SDLK_UP:
			return HandleBroadcast(MCommand(Command::UP));
		case SDLK_DOWN:
			return HandleBroadcast(MCommand(Command::DOWN));
		case SDLK_LEFT:
			return HandleBroadcast(MCommand(Command::LEFT));
		case SDLK_RIGHT:
			return HandleBroadcast(MCommand(Command::RIGHT));
		case SDLK_SPACE:
			return HandleBroadcast(MCommand(Command::GREEN));
		case SDLK_RETURN:
			return HandleBroadcast(MCommand(Command::START));
		case SDLK_ESCAPE:
			return HandleBroadcast(MCommand(Command::RED));
		case SDLK_COMMA:
			return HandleBroadcast(MCommand(Command::PREVIOUS));
		case SDLK_PERIOD:
			return HandleBroadcast(MCommand(Command::NEXT));
		case SDLK_BACKSPACE:
			return HandleBroadcast(MCommand(Command::BACK));
		case SDLK_TAB:
			return HandleBroadcast(MCommand(Command::YELLOW));
		case SDLK_z:
			return HandleBroadcast(MCommand(Command::BLUE));
		}
		return true;
	}


	bool AspirantApplication::OnSdlEvent(const SDL_Event& evt)
	{
		if (evt.type == SDL_QUIT)
		{
			uiState = UIState::QUIT;
		}
		else if (evt.type == SDL_KEYDOWN)
		{
			return OnKeyDown(evt.key);
		}
		return true;
	}

	AspirantApplication application;
}