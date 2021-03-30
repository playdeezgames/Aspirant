#include <SDL.h>
#include <string>
#include <optional>
#include "UIState.h"
#include "Command.h"
#include "Application.Renderer.h"
#include "Graphics.Colors.h"
#include "Graphics.Textures.h"
#include "Graphics.Sprites.h"
#include "Graphics.Fonts.h"
#include "Graphics.Layouts.h"
#include "Common.Sounds.h"
#include "Options.h"
#include "Game.Descriptors.h"
#include "Game.ScenarioDescriptors.h"
#include <map>
#include "Context.Editor.NewRoom.h"
#include "Application.MouseMotion.h"
#include "Application.Command.h"
#include "Application.TextInput.h"
#include "Application.Update.h"
#include "Application.MouseWheel.h"
#include "Application.MouseButtonDown.h"
#include "Application.MouseButtonUp.h"
#include "Application.UIState.h"
namespace state::About { void Start(); }
namespace state::ConfirmQuit { void Start(); }
namespace state::editor::Avatar { void Start(); }
namespace state::editor::NewRoom { void Start(); }
namespace state::editor::PickDescriptor { void Start(); }
namespace state::editor::PickRoom { void Start(); }
namespace state::editor::RoomCells { void Start(); }
namespace state::editor::Scenario { void Start(); }
namespace state::editor::ScenarioDescriptor { void Start(); }
namespace state::editor::Scenarios { void Start(); }
namespace state::editor::Start { void Start(); }
namespace state::MainMenu { void Start(); }
namespace state::Options { void Start(); }
namespace state::player::NewGame { void Start(); }
namespace state::player::Start { void Start(); }
namespace state::Splash { void Start(); }
namespace state::Start { void Start(); }
namespace Application
{
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
			application::Command::Handle(command.value());
		}
	}

	static std::map<Uint8, Command> controllerButtonCommand = 
	{
		{(Uint8)SDL_CONTROLLER_BUTTON_DPAD_DOWN, Command::DOWN},
		{(Uint8)SDL_CONTROLLER_BUTTON_DPAD_UP, Command::UP},
		{(Uint8)SDL_CONTROLLER_BUTTON_DPAD_LEFT, Command::LEFT},
		{(Uint8)SDL_CONTROLLER_BUTTON_DPAD_RIGHT, Command::RIGHT},
		{(Uint8)SDL_CONTROLLER_BUTTON_A, Command::GREEN },
		{(Uint8)SDL_CONTROLLER_BUTTON_B, Command::RED},
		{(Uint8)SDL_CONTROLLER_BUTTON_X, Command::BLUE},
		{(Uint8)SDL_CONTROLLER_BUTTON_Y, Command::YELLOW},
		{(Uint8)SDL_CONTROLLER_BUTTON_BACK, Command::BACK},
		{(Uint8)SDL_CONTROLLER_BUTTON_START, Command::START},
		{(Uint8)SDL_CONTROLLER_BUTTON_LEFTSHOULDER, Command::PREVIOUS},
		{(Uint8)SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, Command::NEXT}
	};

	static void HandleControllerButtonDown(const SDL_ControllerButtonEvent& evt)
	{
		auto iter = controllerButtonCommand.find(evt.button);
		if (iter != controllerButtonCommand.end())
		{
			::application::Command::Handle(iter->second);
		}
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
		state::Splash::Start,
		state::MainMenu::Start,
		state::About::Start,
		state::ConfirmQuit::Start,
		state::Options::Start,
		state::Start::Start,
		state::editor::Start::Start,
		state::editor::Scenarios::Start,
		state::editor::Scenario::Start,
		state::editor::PickRoom::Start,
		state::editor::NewRoom::Start,
		state::editor::ScenarioDescriptor::Start,
		state::editor::RoomCells::Start,
		state::editor::PickDescriptor::Start,
		::context::editor::NewRoom::Start,
		state::player::Start::Start,
		state::player::NewGame::Start,
		state::editor::Avatar::Start,
		state::editor::Scenario::Start
	};

	void Start(SDL_Renderer* renderer, const std::vector<std::string>& arguments)
	{
		graphics::Colors::Start(COLOR);
		graphics::Textures::InitializeFromFile(renderer, TEXTURE);
		graphics::Sprites::InitializeFromFile(SPRITE);
		graphics::Fonts::Start(FONTS);
		graphics::Layouts::Start(LAYOUTS);
		common::Sounds::Start(SFX, MUX);
		Options::Start(OPTIONS);
		game::Descriptors::Start(DESCRIPTORS);
		game::ScenarioDescriptors::Load(SCENARIOS);

		for (auto starter : starters)
		{
			starter();
		}
	}

	bool IsRunning()
	{
		return ::application::UIState::Read() != ::UIState::QUIT;
	}

	void Update(Uint32 ticks)
	{
		application::Update::Handle(ticks);
	}

	void HandleEvent(const SDL_Event& evt)
	{
		switch (evt.type)
		{
		case SDL_QUIT:
			::application::UIState::Write(::UIState::QUIT);
			break;
		case SDL_KEYDOWN:
			::Application::HandleKeyDown(evt.key);
			break;
		case SDL_TEXTINPUT:
			::application::TextInput::Handle(evt.text);
			break;
		case SDL_CONTROLLERBUTTONDOWN:
			::Application::HandleControllerButtonDown(evt.cbutton);
			break;
		case SDL_MOUSEMOTION:
			::application::MouseMotion::Handle(evt.motion);
			break;
		case SDL_MOUSEBUTTONDOWN:
			::application::MouseButtonDown::Handle(evt.button);
			break;
		case SDL_MOUSEBUTTONUP:
			::application::MouseButtonUp::Handle(evt.button);
			break;
		case SDL_MOUSEWHEEL:
			::application::MouseWheel::Handle(evt.wheel);
			break;
		}
	}
}