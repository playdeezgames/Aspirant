#include "OptionsStateHandler.h"
#include "AspirantApplication.h"
#include "UIState.h"
namespace aspirant::navigationui::OptionsStateHandler
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
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::OPTIONS, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::OPTIONS, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::OPTIONS, OnUpdate);
	}
}
