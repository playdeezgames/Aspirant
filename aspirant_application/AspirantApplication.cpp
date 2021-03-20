#include <SDL.h>
#include <string>
#include "UIState.h"
#include "Command.h"
#include <optional>
#include "StringManager.h"
#include "IntManager.h"
#include "FlagManager.h"
#include "AspirantApplication.h"
#include "FinishManager.h"
#include "ColorManager.h"
#include "TextureManager.h"
#include "SpriteManager.h"
#include "FontManager.h"
#include "LayoutManager.h"
#include "SoundManager.h"
#include "OptionsManager.h"
#include "DescriptorManager.h"
#include <map>
namespace aspirant::ConfigurationConstants
{
	const std::string TEXTURE = "config/graphics/textures.json";
	const std::string SPRITE = "config/graphics/sprites.json";
	const std::string COLOR = "config/graphics/colors.json";
	const std::string FONTS = "config/graphics/fonts.json";
	const std::string LAYOUTS = "config/ui/layouts.json";
	const std::string STRINGS = "config/data/strings.json";
	const std::string INTS = "config/data/ints.json";
	const std::string FLAGS = "config/data/flags.json";
	const std::string OPTIONS = "config/options.json";
	const std::string SFX = "config/audio/sfx.json";
	const std::string MUX = "config/audio/mux.json";
	const std::string DESCRIPTORS = "config/game/descriptors.json";
	const std::string SCENARIOS = "scenarios/scenarios.json";
}
namespace aspirant::Application
{
	static aspirant::commonui::UIState uiState = aspirant::commonui::UIState::SPLASH;

	void SetUIState(const aspirant::commonui::UIState& state)
	{
		uiState = state;
	}

	const aspirant::commonui::UIState& GetUIState()
	{
		return uiState;
	}

	static std::map<aspirant::commonui::UIState, aspirant::commonui::CommandHandler> commandHandlers;

	static void HandleCommand(const aspirant::commonui::Command& command)
	{
		auto handler = commandHandlers.find(GetUIState());
		if (handler != commandHandlers.end())
		{
			handler->second(command);
		}
	}

	static std::optional<aspirant::commonui::Command> KeyCodeToCommand(const SDL_Keycode& code)
	{
		switch (code)
		{
		case SDLK_UP:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::UP);
		case SDLK_DOWN:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::DOWN);
		case SDLK_LEFT:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::LEFT);
		case SDLK_RIGHT:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::RIGHT);
		case SDLK_SPACE:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::GREEN);
		case SDLK_RETURN:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::START);
		case SDLK_ESCAPE:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::RED);
		case SDLK_COMMA:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::PREVIOUS);
		case SDLK_PERIOD:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::NEXT);
		case SDLK_BACKSPACE:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::BACK);
		case SDLK_TAB:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::YELLOW);
		case SDLK_z:
			return std::optional<aspirant::commonui::Command>(aspirant::commonui::Command::BLUE);
		default:
			return std::optional<aspirant::commonui::Command>();
		}
	}

	static void HandleKeyDown(const SDL_KeyboardEvent& evt)
	{
		auto command = KeyCodeToCommand(evt.keysym.sym);
		if (command)
		{
			HandleCommand(command.value());
		}
	}

	static std::map<aspirant::commonui::UIState, TextInputHandler> textInputHandlers;

	static void HandleTextInput(const SDL_TextInputEvent& evt)
	{
		auto handler = textInputHandlers.find(GetUIState());
		if (handler != textInputHandlers.end())
		{
			handler->second(evt.text);
		}
	}

	void SetCommandHandler(const aspirant::commonui::UIState& state, aspirant::commonui::CommandHandler handler)
	{
		commandHandlers[state] = handler;
	}

	void SetTextInputHandler(const aspirant::commonui::UIState& state, TextInputHandler handler)
	{
		textInputHandlers[state] = handler;
	}

	static std::map<aspirant::commonui::UIState, UpdateHandler> updateHandlers;

	void SetUpdateHandler(const aspirant::commonui::UIState& state, UpdateHandler handler)
	{
		updateHandlers[state] = handler;
	}

	static std::map<aspirant::commonui::UIState, RenderHandler> renderHandlers;

	void SetRenderHandler(const aspirant::commonui::UIState& state, RenderHandler handler)
	{
		renderHandlers[state] = handler;
	}
}
namespace tggd::common::Application
{

	namespace ConfigurationConstants
	{
		std::string APPLICATION = "config/ui/application.json";
	}

	void Start(SDL_Renderer* renderer)
	{
		tggd::data::StringManager::Start(aspirant::ConfigurationConstants::STRINGS);
		tggd::data::IntManager::Start(aspirant::ConfigurationConstants::INTS);
		tggd::data::FlagManager::Start(aspirant::ConfigurationConstants::FLAGS);
		tggd::graphics::ColorManager::Start(aspirant::ConfigurationConstants::COLOR);
		tggd::graphics::TextureManager::Start(renderer, aspirant::ConfigurationConstants::TEXTURE);
		tggd::graphics::SpriteManager::Start(aspirant::ConfigurationConstants::SPRITE);
		tggd::graphics::FontManager::Start(aspirant::ConfigurationConstants::FONTS);
		tggd::graphics::LayoutManager::Start(aspirant::ConfigurationConstants::LAYOUTS);
		tggd::common::SoundManager::Start(aspirant::ConfigurationConstants::SFX, aspirant::ConfigurationConstants::MUX);
		aspirant::navigationui::OptionsManager::Start(aspirant::ConfigurationConstants::OPTIONS);
		aspirant::game::DescriptorManager::Start(aspirant::ConfigurationConstants::DESCRIPTORS);
		//scenarios.Load();

		//new aspirant::navigationui::SplashStateHandler(this, uiContext);
		//new aspirant::navigationui::MainMenuStateHandler(this, uiContext);
		//new aspirant::navigationui::AboutStateHandler(this, uiContext);
		//new aspirant::navigationui::ConfirmQuitStateHandler(this, uiContext);
		//new aspirant::navigationui::OptionsStateHandler(this, soundManager, optionsManager, uiContext);
		//new aspirant::navigationui::StartGameStateHandler(this, uiContext);
		//new aspirant::editorui::StartEditorStateHandler(this, editorContext, uiContext);
		//new aspirant::editorui::EditScenarioSelectorStateHandler(this, editorContext, uiContext);
		//new aspirant::editorui::EditScenarioStateHandler(this, editorContext, uiContext);
		//new aspirant::editorui::EditPickRoomStateHandler(this, editorContext, uiContext);
		//new aspirant::editorui::EditNewRoomStateHandler(this, editorContext, uiContext);
		//new aspirant::editorui::EditScenarioDescriptorStateHandler(this, editorContext, uiContext);
		//new aspirant::editorui::EditNavigateRoomStateHandler
		//(
		//	this,
		//	editorContext,
		//	uiContext,
		//	roomRenderer,
		//	roomCellObjectsRenderer,
		//	descriptorSelectorRenderer
		//);
		//new aspirant::editorui::EditDescriptorSelectorStateHandler
		//(
		//	this,
		//	editorContext,
		//	uiContext,
		//	roomRenderer,
		//	roomCellObjectsRenderer,
		//	descriptorSelectorRenderer
		//);
	}

	bool IsRunning()
	{
		return aspirant::Application::GetUIState() != aspirant::commonui::UIState::QUIT;
	}

	void Update(Uint32 ticks)
	{
		auto handler = aspirant::Application::updateHandlers.find(aspirant::Application::GetUIState());
		if (handler != aspirant::Application::updateHandlers.end())
		{
			handler->second(ticks);
		}
	}

	void Render(SDL_Renderer* renderer)
	{
		auto handler = aspirant::Application::renderHandlers.find(aspirant::Application::GetUIState());
		if (handler != aspirant::Application::renderHandlers.end())
		{
			handler->second(renderer);
		}
	}

	void HandleEvent(const SDL_Event& evt)
	{
		if (evt.type == SDL_QUIT)
		{
			aspirant::Application::SetUIState(aspirant::commonui::UIState::QUIT);
		}
		else if (evt.type == SDL_KEYDOWN)
		{
			aspirant::Application::HandleKeyDown(evt.key);
		}
		else if (evt.type == SDL_TEXTINPUT)
		{
			aspirant::Application::HandleTextInput(evt.text);
		}
	}

	void Finish()
	{
		tggd::common::FinishManager::Finish();
	}

}
