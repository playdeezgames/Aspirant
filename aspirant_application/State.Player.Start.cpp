#include "State.Player.Start.h"
#include <string>
#include "Command.h"
#include <SDL.h>
#include "Graphics.Layouts.h"
#include "Application.h"
namespace state::player::Start
{
	const std::string LAYOUT_NAME = "StartPlayer";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case Command::BACK:
			Application::SetUIState(UIState::START_GAME);
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::START_PLAYER, OnCommand);
		::Application::SetRenderLayout(::UIState::START_PLAYER, LAYOUT_NAME);
		::Application::SetUpdateHandler(::UIState::START_PLAYER, OnUpdate);
	}
}
