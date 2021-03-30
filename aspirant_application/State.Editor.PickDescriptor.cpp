#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Common.Utility.h"
#include "Context.Editor.PickDescriptor.h"
#include "Application.Command.h"
#include "Application.UIState.h"
namespace state::editor::PickDescriptor
{
	const std::string LAYOUT_NAME = "State.Editor.PickDescriptor";

	static void ChangeIndex(int delta)
	{
		::context::editor::PickDescriptor::SetIndex(
			(size_t)common::Utility::PositiveModulo(
				(int)::context::editor::PickDescriptor::GetIndex() + delta, 
				::context::editor::PickDescriptor::GetCount()));
	}

	static void OnCommand(const ::Command& command)
	{
		const int ROW_DELTA = 7;
		const int COLUMN_DELTA = 1;
		switch (command)
		{
		case ::Command::BACK:
			::application::UIState::SetUIState(::UIState::EDIT_PICK_ROOM);
			break;
		case ::Command::UP:
			ChangeIndex(-ROW_DELTA);
			break;
		case ::Command::DOWN:
			ChangeIndex(+ROW_DELTA);
			break;
		case ::Command::LEFT:
			ChangeIndex(-COLUMN_DELTA);
			break;
		case ::Command::RIGHT:
			ChangeIndex(COLUMN_DELTA);
			break;
		case ::Command::NEXT:
			::application::UIState::SetUIState(::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::EDIT_DESCRIPTOR_SELECTOR, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_DESCRIPTOR_SELECTOR, LAYOUT_NAME);
	}
}
