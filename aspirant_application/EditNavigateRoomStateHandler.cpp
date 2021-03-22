#include "EditNavigateRoomStateHandler.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "RoomRenderer.h"
#include "DescriptorSelectorRenderer.h"
#include "RoomCellObjectsRenderer.h"
#include "EditorRoomViewContext.h"
#include <sstream>
#include "StringManager.h"
#include "EditorContext.h"
#include "Utility.h"
#include "EditorRoomListContext.h"
#include "EditorRoomCellObjectsContext.h"
#include "EditorDescriptorSelectorContext.h"
namespace aspirant::editorui::EditNavigateRoomStateHandler
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";
	const std::string LAYOUT_ROOM_VIEW_POSITION = "RoomViewPosition";
	const std::string TEXT_ROOM_VIEW_POSITION_NAME = "RoomViewPosition.Text.Position";

	static void MoveCursor(const tggd::common::XY<int>& delta)
	{
		int newCursorX = (int)aspirant::editor::context::EditorRoomViewContext::GetCursor().GetX() + delta.GetX();
		int newCursorY = (int)aspirant::editor::context::EditorRoomViewContext::GetCursor().GetY() + delta.GetY();
		auto room = aspirant::editor::context::EditorRoomListContext::GetRoom();
		newCursorX = tggd::common::Utility::PositiveModulo(newCursorX, room->GetColumns());
		newCursorY = tggd::common::Utility::PositiveModulo(newCursorY, room->GetRows());
		aspirant::editor::context::EditorRoomViewContext::SetCursor({ (size_t)newCursorX, (size_t)newCursorY });
		aspirant::editor::context::EditorRoomCellObjectsContext::Reset();
	}

	static void PlaceObject()
	{
		auto& cursorPosition = aspirant::editor::context::EditorRoomViewContext::GetCursor();
		auto descriptor = aspirant::editor::context::EditorDescriptorSelectorContext::GetDescriptor(aspirant::editor::context::EditorDescriptorSelectorContext::GetIndex());
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
			aspirant::editor::context::EditorContext::SaveScenario();
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
		aspirant::editor::controls::DescriptorSelectorRenderer::Draw(renderer);
		tggd::graphics::LayoutManager::Get(LAYOUT_ROOM_VIEW_POSITION).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		auto& cursorPosition = aspirant::editor::context::EditorRoomViewContext::GetCursor();
		std::stringstream ss;
		ss << "(" << cursorPosition.GetX() << "," << cursorPosition.GetY() << ")";//TODO: magic string
		tggd::data::StringManager::Set(TEXT_ROOM_VIEW_POSITION_NAME, ss.str());
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, OnUpdate);
	}
}
