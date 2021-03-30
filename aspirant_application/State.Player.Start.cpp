#include <string>
#include "Command.h"
#include <SDL.h>
#include "Graphics.Layouts.h"
#include "Application.Renderer.h"
#include "Application.Command.h"
#include "Application.UIState.h"
namespace state::player::Start
{
	const std::string LAYOUT_NAME = "State.Player.Start";
	const std::string MENU_ID = "Start";

	enum class StartGameItem
	{
		NEW,
		LOAD,
		BACK
	};

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case Command::UP:
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case Command::BACK:
			application::UIState::Write(::UIState::START_GAME);
			break;
		}
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::START_PLAYER, OnCommand);
		::application::Renderer::SetRenderLayout(::UIState::START_PLAYER, LAYOUT_NAME);
	}
}
