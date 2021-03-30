#include "Application.UIState.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Application.Command.h"
namespace state::About
{
	const std::string LAYOUT_NAME = "State.About";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::application::UIState::SetUIState(::UIState::MAIN_MENU);
			break;
		}
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::ABOUT, OnCommand);
		::Application::SetRenderLayout(::UIState::ABOUT, LAYOUT_NAME);
	}
}
