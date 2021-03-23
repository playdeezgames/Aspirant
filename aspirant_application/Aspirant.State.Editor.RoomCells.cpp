#include "Aspirant.State.Editor.RoomCells.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
#include "Renderer.Editor.Room.h"
#include "Renderer.Editor.PickDescriptor.h"
#include "Renderer.Editor.RoomCellObjects.h"
#include "Aspirant.Context.Editor.RoomView.h"
#include <sstream>
#include "Data.Strings.h"
#include "Aspirant.Context.Editor.Scenario.h"
#include "Common.Utility.h"
#include "Aspirant.Context.Editor.RoomList.h"
#include "Aspirant.Context.Editor.RoomCellObjects.h"
#include "Aspirant.Context.Editor.PickDescriptor.h"
namespace aspirant::state::editor::RoomCells
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";
	const std::string LAYOUT_ROOM_VIEW_POSITION = "RoomViewPosition";
	const std::string TEXT_ROOM_VIEW_POSITION_NAME = "RoomViewPosition.Text.Position";

	static void MoveCursor(const common::XY<int>& delta)
	{
		int newCursorX = (int)aspirant::context::editor::RoomView::GetCursor().GetX() + delta.GetX();
		int newCursorY = (int)aspirant::context::editor::RoomView::GetCursor().GetY() + delta.GetY();
		auto room = aspirant::context::editor::RoomList::GetRoom();
		newCursorX = common::Utility::PositiveModulo(newCursorX, room->GetColumns());
		newCursorY = common::Utility::PositiveModulo(newCursorY, room->GetRows());
		aspirant::context::editor::RoomView::SetCursor({ (size_t)newCursorX, (size_t)newCursorY });
		aspirant::context::editor::RoomCellObjects::Reset();
	}

	static void PlaceObject()
	{
		auto& cursorPosition = aspirant::context::editor::RoomView::GetCursor();
		auto descriptor = aspirant::context::editor::PickDescriptor::GetDescriptor(aspirant::context::editor::PickDescriptor::GetIndex());
		auto roomCell = aspirant::context::editor::RoomList::GetRoom()->GetCell(cursorPosition.GetX(), cursorPosition.GetY());
		auto obj = descriptor->CreateObject();
		if (!roomCell->AddObject(obj))
		{
			delete obj;
		}
	}

	static void RemoveObject()
	{
		auto& cursorPosition = aspirant::context::editor::RoomView::GetCursor();
		auto roomCell = aspirant::context::editor::RoomList::GetRoom()->GetCell(cursorPosition.GetX(), cursorPosition.GetY());
		auto obj = roomCell->RemoveObject();
		if (obj)
		{
			delete obj;
		}
	}

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::BACK:
			aspirant::context::editor::Scenario::Save();
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_PICK_ROOM);
			break;
		case aspirant::Command::UP:
			MoveCursor({ 0,-1 });
			break;
		case aspirant::Command::DOWN:
			MoveCursor({ 0,1 });
			break;
		case aspirant::Command::LEFT:
			MoveCursor({ -1, 0 });
			break;
		case aspirant::Command::RIGHT:
			MoveCursor({ 1, 0 });
			break;
		case aspirant::Command::GREEN:
			PlaceObject();
			break;
		case aspirant::Command::RED:
			RemoveObject();
			break;
		case aspirant::Command::NEXT:
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_DESCRIPTOR_SELECTOR);
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
		auto& cursorPosition = aspirant::context::editor::RoomView::GetCursor();
		std::stringstream ss;
		ss << "(" << cursorPosition.GetX() << "," << cursorPosition.GetY() << ")";//TODO: magic string
		::data::Strings::Set(TEXT_ROOM_VIEW_POSITION_NAME, ss.str());
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::UIState::EDIT_NAVIGATE_ROOM, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::EDIT_NAVIGATE_ROOM, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::EDIT_NAVIGATE_ROOM, OnUpdate);
	}
}
