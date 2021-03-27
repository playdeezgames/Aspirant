#include "State.Editor.PickDescriptor.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Renderer.Editor.Room.h"
#include "Renderer.Editor.Cell.h"
#include "Renderer.Editor.PickDescriptor.h"
#include "Common.Utility.h"
#include "Context.Editor.PickDescriptor.h"
namespace state::editor::PickDescriptor
{
	const std::string LAYOUT_NAME = "State.Editor.PickDescriptor";

	static void ChangeIndex(int delta)
	{
		::context::editor::PickDescriptor::SetIndex(
			(size_t)common::Utility::PositiveModulo(
				::context::editor::PickDescriptor::GetIndex() + delta, 
				::context::editor::PickDescriptor::GetCount()));
	}

	static void OnCommand(const ::Command& command)
	{
		const int ROW_DELTA = 7;
		const int COLUMN_DELTA = 1;
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(::UIState::EDIT_PICK_ROOM);
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
			::Application::SetUIState(::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_DESCRIPTOR_SELECTOR, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_DESCRIPTOR_SELECTOR, LAYOUT_NAME);
	}
}
