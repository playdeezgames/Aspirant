#include "ConfirmQuitStateHandler.h"
#include "AspirantApplication.h"
#include "UIState.h"
namespace aspirant::navigationui::ConfirmQuitStateHandler
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
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::CONFIRM_QUIT, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::CONFIRM_QUIT, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::CONFIRM_QUIT, OnUpdate);
	}
}
