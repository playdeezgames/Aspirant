#include "Graphics.Layouts.h"
#include "Application.h"
namespace state::ConfirmQuit
{
	const std::string LAYOUT_NAME = "State.ConfirmQuit";
	const std::string MENU_ID = "ConfirmQuit";

	enum class ConfirmQuitItem
	{
		NO,
		YES
	};

	static void ActivateItem()
	{
		switch ((ConfirmQuitItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME,MENU_ID).value())
		{
		case ConfirmQuitItem::NO:
			::Application::SetUIState(::UIState::MAIN_MENU);
			return;
		case ConfirmQuitItem::YES:
			::Application::SetUIState(::UIState::QUIT);
			return;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::CONFIRM_QUIT, OnCommand);
		::Application::SetRenderLayout(::UIState::CONFIRM_QUIT, LAYOUT_NAME);
	}
}