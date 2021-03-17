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
#include "EditDescriptorSelectorStateHandler.h"
#include "ConfigurationConstants.h"
namespace aspirant
{
	AspirantApplication::AspirantApplication()
		: tggd::common::Application(ConfigurationConstants::APPLICATION)
		, finishManager()
		, textureManager(finishManager)
		, spriteManager(finishManager)
		, colorManager(finishManager)
		, fontManager(finishManager, spriteManager, colorManager)
		, stringManager()
		, intManager()
		, flagManager()
		, soundManager(finishManager)
		, optionsManager(soundManager, ConfigurationConstants::OPTIONS)
		, layoutManager(finishManager, spriteManager, colorManager, fontManager, stringManager, intManager, flagManager)
		, uiState(aspirant::commonui::UIState::SPLASH)
		, descriptors(finishManager)
		, scenarios(finishManager, ConfigurationConstants::SCENARIOS)
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
		stringManager.Start(ConfigurationConstants::STRINGS);
		intManager.Start(ConfigurationConstants::INTS);
		flagManager.Start(ConfigurationConstants::FLAGS);
		colorManager.Start(ConfigurationConstants::COLOR);
		textureManager.Start(renderer, ConfigurationConstants::TEXTURE);
		spriteManager.Start(textureManager, ConfigurationConstants::SPRITE);
		fontManager.Start(ConfigurationConstants::FONTS);
		layoutManager.Start(ConfigurationConstants::LAYOUTS);
		soundManager.Start(ConfigurationConstants::SFX, ConfigurationConstants::MUX);
		optionsManager.Start();
		descriptors.Start(ConfigurationConstants::DESCRIPTORS);
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
		new aspirant::editorui::EditDescriptorSelectorStateHandler
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
		if (aspirant::commonui::MSetUIState::IsMSetUIState(message))
		{
			return OnSetUIState(aspirant::commonui::MSetUIState::ToMSetUIState(message)->GetState());
		}
		else if (tggd::common::MEvent::IsMEvent(message))
		{
			return OnSdlEvent(tggd::common::MEvent::ToMEvent(message)->GetEvent());
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