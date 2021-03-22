#include "SplashStateHandler.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
namespace aspirant::navigationui::SplashStateHandler
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
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		ticksLeft = (ticksLeft > ticks) ? (ticksLeft - ticks) : (0);
		if (ticksLeft == 0)
		{
			aspirant::Application::SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			ticksLeft = TICKS_TOTAL;
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::SPLASH, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::SPLASH, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::SPLASH, OnUpdate);
	}
}
