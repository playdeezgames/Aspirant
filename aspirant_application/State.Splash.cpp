#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Application.Command.h"
#include "Application.Update.h"
#include "Application.UIState.h"
namespace state::Splash
{
	const size_t TICKS_TOTAL = 3000;
	const std::string LAYOUT_NAME = "State.Splash";
	static size_t ticksLeft = TICKS_TOTAL;

	static void OnCommand(const ::Command& command)
	{
		ticksLeft = 0;
	}

	static void OnUpdate(const Uint32& ticks)
	{
		ticksLeft = (ticksLeft > ticks) ? (ticksLeft - ticks) : (0);
		if (ticksLeft == 0)
		{
			::application::UIState::SetUIState(::UIState::MAIN_MENU);
			ticksLeft = TICKS_TOTAL;
		}
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::SPLASH, OnCommand);
		::Application::SetRenderLayout(::UIState::SPLASH, LAYOUT_NAME);
		::application::Update::AddHandler(::UIState::SPLASH, OnUpdate);
	}
}
