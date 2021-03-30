#include "Application.Renderer.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Context.Editor.RoomView.h"
#include <sstream>
#include "Context.Editor.Scenario.h"
#include "Common.Utility.h"
#include "Context.Editor.Rooms.h"
#include "Context.Editor.Cell.h"
#include "Context.Editor.PickDescriptor.h"
#include "Application.Command.h"
#include "Application.Update.h"
#include "Application.UIState.h"
namespace state::editor::RoomCells
{
	const std::string LAYOUT_NAME = "State.Editor.RoomCells";
	const std::string POSITION_TEXT_ID = "Position";

	static void MoveCursor(const common::XY<int>& delta)
	{
		int newCursorX = (int)::context::editor::RoomView::GetCursor().GetX() + delta.GetX();
		int newCursorY = (int)::context::editor::RoomView::GetCursor().GetY() + delta.GetY();
		auto room = ::context::editor::Rooms::GetRoom();
		newCursorX = common::Utility::PositiveModulo(newCursorX, room.GetColumns());
		newCursorY = common::Utility::PositiveModulo(newCursorY, room.GetRows());
		::context::editor::RoomView::SetCursor({ (size_t)newCursorX, (size_t)newCursorY });
		::context::editor::Cell::Reset();
	}

	static void PlaceObject()
	{
		auto& cursorPosition = ::context::editor::RoomView::GetCursor();
		auto descriptor = ::context::editor::PickDescriptor::GetDescriptor(::context::editor::PickDescriptor::GetIndex());
		auto roomCell = ::context::editor::Rooms::GetRoom().GetCell(cursorPosition.GetX(), cursorPosition.GetY());
		if (descriptor.CanCover(roomCell->GetObject()))
		{
			roomCell->AddObject(descriptor);
		}
	}

	static void RemoveObject()
	{
		auto& cursorPosition = ::context::editor::RoomView::GetCursor();
		auto roomCell = ::context::editor::Rooms::GetRoom().GetCell(cursorPosition.GetX(), cursorPosition.GetY());
		roomCell->RemoveObject();
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::context::editor::Scenario::Save();
			::application::UIState::Write(::UIState::EDIT_PICK_ROOM);
			break;
		case ::Command::UP:
			MoveCursor({ 0,-1 });
			break;
		case ::Command::DOWN:
			MoveCursor({ 0,1 });
			break;
		case ::Command::LEFT:
			MoveCursor({ -1, 0 });
			break;
		case ::Command::RIGHT:
			MoveCursor({ 1, 0 });
			break;
		case ::Command::GREEN:
			PlaceObject();
			break;
		case ::Command::RED:
			RemoveObject();
			break;
		case ::Command::NEXT:
			::application::UIState::Write(::UIState::EDIT_DESCRIPTOR_SELECTOR);
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
		auto& cursorPosition = ::context::editor::RoomView::GetCursor();
		std::stringstream ss;
		ss << "(" << cursorPosition.GetX() << "," << cursorPosition.GetY() << ")";//TODO: magic string
		graphics::Layouts::SetTextText(LAYOUT_NAME, POSITION_TEXT_ID, ss.str());
	}

	void Start()
	{
		application::Command::SetHandler(::UIState::EDIT_NAVIGATE_ROOM, OnCommand);
		application::Renderer::SetRenderLayout(::UIState::EDIT_NAVIGATE_ROOM, LAYOUT_NAME);
		application::Update::AddHandler(::UIState::EDIT_NAVIGATE_ROOM, OnUpdate);
	}
}
