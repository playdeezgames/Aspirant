#include "State.About.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
namespace state::About
{
	const std::string LAYOUT_NAME = "About";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::ABOUT, OnCommand);
		::Application::SetRenderLayout(::UIState::ABOUT, LAYOUT_NAME);
	}
}
