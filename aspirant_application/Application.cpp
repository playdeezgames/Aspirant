#include <SDL.h>
#include <string>
#include <optional>
#include "UIState.h"
#include "Command.h"
#include "Data.Strings.h"
#include "Data.Ints.h"
#include "Data.Bools.h"
#include "Application.h"
#include "Common.Finishers.h"
#include "Graphics.Colors.h"
#include "Graphics.Textures.h"
#include "Graphics.Sprites.h"
#include "Graphics.Fonts.h"
#include "Graphics.Layouts.h"
#include "Common.Sounds.h"
#include "Options.h"
#include "Game.Descriptors.h"
#include "Game.ScenarioDescriptors.h"
#include "Aspirant.State.Splash.h"
#include "Aspirant.State.MainMenu.h"
#include "Aspirant.State.About.h"
#include "Aspirant.State.ConfirmQuit.h"
#include "Aspirant.State.Options.h"
#include "Aspirant.State.Start.h"
#include "Aspirant.State.Editor.Start.h"
#include "Aspirant.State.Editor.Scenarios.h"
#include "Aspirant.State.Editor.Scenario.h"
#include "Aspirant.State.Editor.PickRoom.h"
#include <map>
#include "Aspirant.State.Editor.NewRoom.h"
#include "Aspirant.State.Editor.ScenarioDescriptor.h"
#include "Aspirant.State.Editor.RoomCells.h"
#include "Aspirant.State.Editor.PickDescriptor.h"
#include "Aspirant.Context.Editor.NewRoom.h"
namespace Application
{
	static ::UIState uiState = ::UIState::SPLASH;

	void SetUIState(const ::UIState& state)
	{
		uiState = state;
	}

	const ::UIState& GetUIState()
	{
		return uiState;
	}

	static std::map<::UIState, Application::CommandHandler> commandHandlers;

	static void HandleCommand(const ::Command& command)
	{
		auto handler = commandHandlers.find(GetUIState());
		if (handler != commandHandlers.end())
		{
			handler->second(command);
		}
	}

	static std::optional<::Command> KeyCodeToCommand(const SDL_Keycode& code)
	{
		switch (code)
		{
		case SDLK_UP:
			return std::optional<::Command>(::Command::UP);
		case SDLK_DOWN:
			return std::optional<::Command>(::Command::DOWN);
		case SDLK_LEFT:
			return std::optional<::Command>(::Command::LEFT);
		case SDLK_RIGHT:
			return std::optional<::Command>(::Command::RIGHT);
		case SDLK_SPACE:
			return std::optional<::Command>(::Command::GREEN);
		case SDLK_RETURN:
			return std::optional<::Command>(::Command::START);
		case SDLK_ESCAPE:
			return std::optional<::Command>(::Command::RED);
		case SDLK_COMMA:
			return std::optional<::Command>(::Command::PREVIOUS);
		case SDLK_PERIOD:
			return std::optional<::Command>(::Command::NEXT);
		case SDLK_BACKSPACE:
			return std::optional<::Command>(::Command::BACK);
		case SDLK_TAB:
			return std::optional<::Command>(::Command::YELLOW);
		case SDLK_z:
			return std::optional<::Command>(::Command::BLUE);
		default:
			return std::optional<::Command>();
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

	static std::map<::UIState, TextInputHandler> textInputHandlers;

	static void HandleTextInput(const SDL_TextInputEvent& evt)
	{
		auto handler = textInputHandlers.find(GetUIState());
		if (handler != textInputHandlers.end())
		{
			handler->second(evt.text);
		}
	}

	void SetCommandHandler(const ::UIState& state, Application::CommandHandler handler)
	{
		commandHandlers[state] = handler;
	}

	void SetTextInputHandler(const ::UIState& state, TextInputHandler handler)
	{
		textInputHandlers[state] = handler;
	}

	static std::map<::UIState, UpdateHandler> updateHandlers;

	void SetUpdateHandler(const ::UIState& state, UpdateHandler handler)
	{
		updateHandlers[state] = handler;
	}

	static std::map<::UIState, RenderHandler> renderHandlers;

	void SetRenderHandler(const ::UIState& state, RenderHandler handler)
	{
		renderHandlers[state] = handler;
	}
}
namespace common::Application
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

	static std::vector<void(*)()> starters = 
	{
		aspirant::state::Splash::Start,
		aspirant::state::MainMenu::Start,
		aspirant::state::About::Start,
		aspirant::state::ConfirmQuit::Start,
		aspirant::state::Options::Start,
		aspirant::state::Start::Start,
		aspirant::state::editor::Start::Start,
		aspirant::state::editor::Scenarios::Start,
		aspirant::state::editor::Scenario::Start,
		aspirant::state::editor::PickRoom::Start,
		aspirant::state::editor::NewRoom::Start,
		aspirant::state::editor::ScenarioDescriptor::Start,
		aspirant::state::editor::RoomCells::Start,
		aspirant::state::editor::PickDescriptor::Start,
		aspirant::context::editor::NewRoom::Start
	};

	void Start(SDL_Renderer* renderer)
	{
		data::Strings::Start(STRINGS);
		data::Ints::Start(INTS);
		data::Bools::Start(FLAGS);
		graphics::Colors::Start(COLOR);
		graphics::Textures::Start(renderer, TEXTURE);
		graphics::Sprites::Start(SPRITE);
		graphics::Fonts::Start(FONTS);
		graphics::Layouts::Start(LAYOUTS);
		common::Sounds::Start(SFX, MUX);
		::Options::Start(OPTIONS);
		game::Descriptors::Start(DESCRIPTORS);
		game::ScenarioDescriptors::Load(SCENARIOS);

		for (auto starter : starters)
		{
			starter();
		}
	}

	bool IsRunning()
	{
		return ::Application::GetUIState() != ::UIState::QUIT;
	}

	void Update(Uint32 ticks)
	{
		auto handler = ::Application::updateHandlers.find(::Application::GetUIState());
		if (handler != ::Application::updateHandlers.end())
		{
			handler->second(ticks);
		}
	}

	void Render(SDL_Renderer* renderer)
	{
		auto handler = ::Application::renderHandlers.find(::Application::GetUIState());
		if (handler != ::Application::renderHandlers.end())
		{
			handler->second(renderer);
		}
	}

	void HandleEvent(const SDL_Event& evt)
	{
		if (evt.type == SDL_QUIT)
		{
			::Application::SetUIState(::UIState::QUIT);
		}
		else if (evt.type == SDL_KEYDOWN)
		{
			::Application::HandleKeyDown(evt.key);
		}
		else if (evt.type == SDL_TEXTINPUT)
		{
			::Application::HandleTextInput(evt.text);
		}
	}

	void Finish()
	{
		common::Finishers::Finish();
	}
}
