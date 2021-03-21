#include "StartGameStateHandler.h"
#include "AspirantApplication.h"
#include "UIState.h"
namespace aspirant::navigationui::StartGameStateHandler
{
	static void OnCommand(const aspirant::commonui::Command& command)
	{

	}

	static void OnDraw(SDL_Renderer* renderer)
	{

	}

	static void OnUpdate(const Uint32& ticks)
	{

	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::START_GAME, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::START_GAME, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::START_GAME, OnUpdate);
	}
}
