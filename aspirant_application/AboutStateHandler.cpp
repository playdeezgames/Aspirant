#include "AboutStateHandler.h"
#include "AspirantApplication.h"
#include "UIState.h"
namespace aspirant::navigationui::AboutStateHandler
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
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::ABOUT, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::ABOUT, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::ABOUT, OnUpdate);
	}
}
