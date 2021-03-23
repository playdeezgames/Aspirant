#include "Aspirant.State.Splash.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
namespace aspirant::state::Splash
{
	const size_t TICKS_TOTAL = 3000;
	const std::string LAYOUT_NAME = "Splash";
	static size_t ticksLeft = TICKS_TOTAL;

	static void OnCommand(const aspirant::Command& command)
	{
		ticksLeft = 0;
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		ticksLeft = (ticksLeft > ticks) ? (ticksLeft - ticks) : (0);
		if (ticksLeft == 0)
		{
			aspirant::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			ticksLeft = TICKS_TOTAL;
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::UIState::SPLASH, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::SPLASH, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::SPLASH, OnUpdate);
	}
}
