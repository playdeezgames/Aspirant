#include "Aspirant.State.Editor.RoomCells.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "RoomRenderer.h"
#include "Renderer.Editor.PickDescriptor.h"
#include "RoomCellObjectsRenderer.h"
#include "EditorRoomViewContext.h"
#include <sstream>
#include "Data.Strings.h"
#include "Aspirant.Context.Editor.Scenario.h"
#include "Common.Utility.h"
#include "EditorRoomListContext.h"
#include "EditorRoomCellObjectsContext.h"
#include "Aspirant.Context.Editor.PickDescriptor.h"
namespace aspirant::state::editor::RoomCells
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";
	const std::string LAYOUT_ROOM_VIEW_POSITION = "RoomViewPosition";
	const std::string TEXT_ROOM_VIEW_POSITION_NAME = "RoomViewPosition.Text.Position";

	static void MoveCursor(const common::XY<int>& delta)
	{
		int newCursorX = (int)aspirant::editor::context::EditorRoomViewContext::GetCursor().GetX() + delta.GetX();
		int newCursorY = (int)aspirant::editor::context::EditorRoomViewContext::GetCursor().GetY() + delta.GetY();
		auto room = aspirant::editor::context::EditorRoomListContext::GetRoom();
		newCursorX = common::Utility::PositiveModulo(newCursorX, room->GetColumns());
		newCursorY = common::Utility::PositiveModulo(newCursorY, room->GetRows());
		aspirant::editor::context::EditorRoomViewContext::SetCursor({ (size_t)newCursorX, (size_t)newCursorY });
		aspirant::editor::context::EditorRoomCellObjectsContext::Reset();
	}

	static void PlaceObject()
	{
		auto& cursorPosition = aspirant::editor::context::EditorRoomViewContext::GetCursor();
		auto descriptor = aspirant::context::editor::PickDescriptor::GetDescriptor(aspirant::context::editor::PickDescriptor::GetIndex());
		auto roomCell = aspirant::editor::context::EditorRoomListContext::GetRoom()->GetCell(cursorPosition.GetX(), cursorPosition.GetY());
		auto obj = descriptor->CreateObject();
		if (!roomCell->AddObject(obj))
		{
			delete obj;
		}
	}

	static void RemoveObject()
	{
		auto& cursorPosition = aspirant::editor::context::EditorRoomViewContext::GetCursor();
		auto roomCell = aspirant::editor::context::EditorRoomListContext::GetRoom()->GetCell(cursorPosition.GetX(), cursorPosition.GetY());
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
			aspirant::context::editor::Scenario::SaveScenario();
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
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
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_DESCRIPTOR_SELECTOR);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
		aspirant::editor::controls::RoomRenderer::Draw(renderer);
		aspirant::editor::controls::RoomCellObjectsRenderer::Draw(renderer);
		renderer::editor::PickDescriptor::Draw(renderer);
		tggd::graphics::LayoutManager::Get(LAYOUT_ROOM_VIEW_POSITION).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		auto& cursorPosition = aspirant::editor::context::EditorRoomViewContext::GetCursor();
		std::stringstream ss;
		ss << "(" << cursorPosition.GetX() << "," << cursorPosition.GetY() << ")";//TODO: magic string
		::data::Strings::Set(TEXT_ROOM_VIEW_POSITION_NAME, ss.str());
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, OnUpdate);
	}
}
