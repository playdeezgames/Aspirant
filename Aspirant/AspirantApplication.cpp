#include "AspirantApplication.h"
#include "Utility.h"
#include "MSetUIState.h"
#include "MEvent.h"
#include "MText.h"
#include "SplashStateHandler.h"
#include "MainMenuStateHandler.h"
#include "AboutStateHandler.h"
#include "ConfirmQuitStateHandler.h"
#include "OptionsStateHandler.h"
#include "StartGameStateHandler.h"
#include "StartEditorStateHandler.h"
#include "EditScenarioSelectorStateHandler.h"
#include "EditScenarioStateHandler.h"
#include "EditPickRoomStateHandler.h"
#include "EditNewRoomStateHandler.h"
#include "EditScenarioDescriptorStateHandler.h"
#include "EditNavigateRoomStateHandler.h"
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
		, uiState(aspirant::commonui::UIState::SPLASH)
		, descriptors(finishManager)
		, scenarios(finishManager, SCENARIOS_CONFIG_FILE)
		, editorContext(descriptors, scenarios)
		, uiContext(uiState, layoutManager, stringManager)
		, roomRenderer(editorContext, spriteManager)
		, roomCellObjectsRenderer(editorContext, spriteManager)
		, descriptorSelectorRenderer(editorContext, spriteManager)
	{

	}

	bool AspirantApplication::IsRunning() const
	{
		return uiState!= aspirant::commonui::UIState::QUIT;
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

		new aspirant::navigationui::SplashStateHandler(this, uiContext);
		new aspirant::navigationui::MainMenuStateHandler(this, uiContext);
		new aspirant::navigationui::AboutStateHandler(this, uiContext);
		new aspirant::navigationui::ConfirmQuitStateHandler(this, uiContext);
		new aspirant::navigationui::OptionsStateHandler(this, soundManager, optionsManager, uiContext);
		new aspirant::navigationui::StartGameStateHandler(this, uiContext);
		new aspirant::editorui::StartEditorStateHandler(this, editorContext, uiContext);
		new aspirant::editorui::EditScenarioSelectorStateHandler(this, editorContext, uiContext);
		new aspirant::editorui::EditScenarioStateHandler(this, editorContext, uiContext);
		new aspirant::editorui::EditPickRoomStateHandler(this, editorContext, uiContext);
		new aspirant::editorui::EditNewRoomStateHandler(this, editorContext, uiContext);
		new aspirant::editorui::EditScenarioDescriptorStateHandler(this, editorContext, uiContext);
		new aspirant::editorui::EditNavigateRoomStateHandler
		(
			this, 
			editorContext, 
			uiContext, 
			roomRenderer, 
			roomCellObjectsRenderer,
			descriptorSelectorRenderer
		);
	}

	void AspirantApplication::Finish()
	{
		finishManager.Finish();
	}

	bool AspirantApplication::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == aspirant::commonui::MSetUIState::MSGID_SetUIState)
		{
			return OnSetUIState(static_cast<const aspirant::commonui::MSetUIState*>(message)->GetState());
		}
		else if (message->GetId() == tggd::common::MEvent::MSGID_SdlEvent)
		{
			return OnSdlEvent(static_cast<const tggd::common::MEvent*>(message)->GetEvent());
		}
		return false;
	}

	bool AspirantApplication::OnSetUIState(const aspirant::commonui::UIState& state)
	{
		uiState = state;
		return true;
	}

	bool AspirantApplication::OnKeyDown(const SDL_KeyboardEvent& keyEvent)
	{
		switch (keyEvent.keysym.sym)
		{
		case SDLK_UP:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::UP));
		case SDLK_DOWN:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::DOWN));
		case SDLK_LEFT:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::LEFT));
		case SDLK_RIGHT:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::RIGHT));
		case SDLK_SPACE:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::GREEN));
		case SDLK_RETURN:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::START));
		case SDLK_ESCAPE:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::RED));
		case SDLK_COMMA:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::PREVIOUS));
		case SDLK_PERIOD:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::NEXT));
		case SDLK_BACKSPACE:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::BACK));
		case SDLK_TAB:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::YELLOW));
		case SDLK_z:
			return HandleBroadcast(aspirant::commonui::MCommand(aspirant::commonui::Command::BLUE));
		}
		return true;
	}

	bool AspirantApplication::OnTextInput(const SDL_TextInputEvent& textEvent)
	{
		return HandleBroadcast(tggd::common::MText(textEvent.text));
	}


	bool AspirantApplication::OnSdlEvent(const SDL_Event& evt)
	{
		if (evt.type == SDL_QUIT)
		{
			uiState = aspirant::commonui::UIState::QUIT;
		}
		else if (evt.type == SDL_KEYDOWN)
		{
			return OnKeyDown(evt.key);
		}
		else if (evt.type == SDL_TEXTINPUT)
		{
			return OnTextInput(evt.text);
		}
		return true;
	}

	AspirantApplication application;
}