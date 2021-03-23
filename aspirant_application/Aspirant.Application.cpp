#include <SDL.h>
#include <string>
#include "Aspirant.UIState.h"
#include "Aspirant.Command.h"
#include <optional>
#include "Data.Strings.h"
#include "Data.Ints.h"
#include "Data.Bools.h"
#include "Aspirant.Application.h"
#include "Common.Finishers.h"
#include "Graphics.Colors.h"
#include "Graphics.Textures.h"
#include "SpriteManager.h"
#include "Graphics.Fonts.h"
#include "Graphics.Layouts.h"
#include "Common.Sounds.h"
#include "Aspirant.Options.h"
#include "Game.Descriptors.h"
#include "Game.ScenarioDescriptors.h"
#include "Aspirant.State.Splash.h"
#include "Aspirant.State.MainMenu.h"
#include "Aspirant.State.About.h"
#include "Aspirant.State.ConfirmQuit.h"
#include "Aspirant.State.Options.h"
#include "Aspirant.State.Start.h"
#include "StartEditorStateHandler.h"
#include "Aspirant.State.Editor.Scenarios.h"
#include "Aspirant.State.Editor.Scenario.h"
#include "Aspirant.State.Editor.PickRoom.h"
#include <map>
#include "Aspirant.State.Editor.NewRoom.h"
#include "Aspirant.State.Editor.ScenarioDescriptor.h"
#include "Aspirant.State.Editor.RoomCells.h"
#include "Aspirant.State.Editor.PickDescriptor.h"
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
	static aspirant::UIState uiState = aspirant::UIState::SPLASH;

	void SetUIState(const aspirant::UIState& state)
	{
		uiState = state;
	}

	const aspirant::UIState& GetUIState()
	{
		return uiState;
	}

	static std::map<aspirant::UIState, aspirant::CommandHandler> commandHandlers;

	static void HandleCommand(const aspirant::Command& command)
	{
		auto handler = commandHandlers.find(GetUIState());
		if (handler != commandHandlers.end())
		{
			handler->second(command);
		}
	}

	static std::optional<aspirant::Command> KeyCodeToCommand(const SDL_Keycode& code)
	{
		switch (code)
		{
		case SDLK_UP:
			return std::optional<aspirant::Command>(aspirant::Command::UP);
		case SDLK_DOWN:
			return std::optional<aspirant::Command>(aspirant::Command::DOWN);
		case SDLK_LEFT:
			return std::optional<aspirant::Command>(aspirant::Command::LEFT);
		case SDLK_RIGHT:
			return std::optional<aspirant::Command>(aspirant::Command::RIGHT);
		case SDLK_SPACE:
			return std::optional<aspirant::Command>(aspirant::Command::GREEN);
		case SDLK_RETURN:
			return std::optional<aspirant::Command>(aspirant::Command::START);
		case SDLK_ESCAPE:
			return std::optional<aspirant::Command>(aspirant::Command::RED);
		case SDLK_COMMA:
			return std::optional<aspirant::Command>(aspirant::Command::PREVIOUS);
		case SDLK_PERIOD:
			return std::optional<aspirant::Command>(aspirant::Command::NEXT);
		case SDLK_BACKSPACE:
			return std::optional<aspirant::Command>(aspirant::Command::BACK);
		case SDLK_TAB:
			return std::optional<aspirant::Command>(aspirant::Command::YELLOW);
		case SDLK_z:
			return std::optional<aspirant::Command>(aspirant::Command::BLUE);
		default:
			return std::optional<aspirant::Command>();
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

	static std::map<aspirant::UIState, TextInputHandler> textInputHandlers;

	static void HandleTextInput(const SDL_TextInputEvent& evt)
	{
		auto handler = textInputHandlers.find(GetUIState());
		if (handler != textInputHandlers.end())
		{
			handler->second(evt.text);
		}
	}

	void SetCommandHandler(const aspirant::UIState& state, aspirant::CommandHandler handler)
	{
		commandHandlers[state] = handler;
	}

	void SetTextInputHandler(const aspirant::UIState& state, TextInputHandler handler)
	{
		textInputHandlers[state] = handler;
	}

	static std::map<aspirant::UIState, UpdateHandler> updateHandlers;

	void SetUpdateHandler(const aspirant::UIState& state, UpdateHandler handler)
	{
		updateHandlers[state] = handler;
	}

	static std::map<aspirant::UIState, RenderHandler> renderHandlers;

	void SetRenderHandler(const aspirant::UIState& state, RenderHandler handler)
	{
		renderHandlers[state] = handler;
	}
}
namespace common::Application
{

	namespace ConfigurationConstants
	{
		std::string APPLICATION = "config/ui/application.json";
	}

	void Start(SDL_Renderer* renderer)
	{
		::data::Strings::Start(aspirant::ConfigurationConstants::STRINGS);
		::data::Ints::Start(aspirant::ConfigurationConstants::INTS);
		::data::Bools::Start(aspirant::ConfigurationConstants::FLAGS);
		::graphics::Colors::Start(aspirant::ConfigurationConstants::COLOR);
		::graphics::Textures::Start(renderer, aspirant::ConfigurationConstants::TEXTURE);
		tggd::graphics::SpriteManager::Start(aspirant::ConfigurationConstants::SPRITE);
		graphics::Fonts::Start(aspirant::ConfigurationConstants::FONTS);
		graphics::Layouts::Start(aspirant::ConfigurationConstants::LAYOUTS);
		common::Sounds::Start(aspirant::ConfigurationConstants::SFX, aspirant::ConfigurationConstants::MUX);
		aspirant::Options::Start(aspirant::ConfigurationConstants::OPTIONS);
		::game::Descriptors::Start(aspirant::ConfigurationConstants::DESCRIPTORS);
		::game::ScenarioDescriptors::Load(aspirant::ConfigurationConstants::SCENARIOS);

		aspirant::state::Splash::Start();
		aspirant::state::MainMenu::Start();
		aspirant::state::About::Start();
		aspirant::state::ConfirmQuit::Start();
		aspirant::state::Options::Start();
		aspirant::state::Start::Start();
		aspirant::editorui::StartEditorStateHandler::Start();
		aspirant::state::editor::Scenarios::Start();
		aspirant::state::editor::Scenario::Start();
		aspirant::state::editor::PickRoom::Start();
		aspirant::state::editor::NewRoom::Start();
		aspirant::state::editor::ScenarioDescriptor::Start();
		aspirant::state::editor::RoomCells::Start();
		aspirant::state::editor::PickDescriptor::Start();
	}

	bool IsRunning()
	{
		return aspirant::Application::GetUIState() != aspirant::UIState::QUIT;
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
			aspirant::Application::SetUIState(aspirant::UIState::QUIT);
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
		common::Finishers::Finish();
	}

}
