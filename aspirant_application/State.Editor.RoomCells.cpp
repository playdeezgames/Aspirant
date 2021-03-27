#include "State.Editor.RoomCells.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Renderer.Editor.Room.h"
#include "Renderer.Editor.PickDescriptor.h"
#include "Renderer.Editor.Cell.h"
#include "Context.Editor.RoomView.h"
#include <sstream>
#include "Data.Strings.h"
#include "Context.Editor.Scenario.h"
#include "Common.Utility.h"
#include "Context.Editor.Rooms.h"
#include "Context.Editor.Cell.h"
#include "Context.Editor.PickDescriptor.h"
namespace state::editor::RoomCells
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";
	const std::string LAYOUT_ROOM_VIEW_POSITION = "RoomViewPosition";
	const std::string TEXT_ROOM_VIEW_POSITION_NAME = "RoomViewPosition.Text.Position";

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
			::Application::SetUIState(::UIState::EDIT_PICK_ROOM);
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
			::Application::SetUIState(::UIState::EDIT_DESCRIPTOR_SELECTOR);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
		renderer::editor::Room::Draw(renderer);
		renderer::editor::RoomCellObjects::Draw(renderer);
		renderer::editor::PickDescriptor::Draw(renderer);
		graphics::Layouts::Get(LAYOUT_ROOM_VIEW_POSITION).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		auto& cursorPosition = ::context::editor::RoomView::GetCursor();
		std::stringstream ss;
		ss << "(" << cursorPosition.GetX() << "," << cursorPosition.GetY() << ")";//TODO: magic string
		::data::Strings::Set(TEXT_ROOM_VIEW_POSITION_NAME, ss.str());
	}

	void Start()
	{
		Application::SetCommandHandler(::UIState::EDIT_NAVIGATE_ROOM, OnCommand);
		Application::SetRenderHandler(::UIState::EDIT_NAVIGATE_ROOM, OnDraw);
		Application::SetUpdateHandler(::UIState::EDIT_NAVIGATE_ROOM, OnUpdate);
	}
}
