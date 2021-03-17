#include "EditNavigateRoomStateHandler.h"
#include "Utility.h"
#include <sstream>
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";
	const std::string LAYOUT_ROOM_VIEW_POSITION = "RoomViewPosition";
	const std::string TEXT_ROOM_VIEW_POSITION_NAME = "RoomViewPosition.Text.Position";

	bool EditNavigateRoomStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		CommonEditorStateHandler::OnDraw(renderer);
		roomRenderer.Draw(renderer);
		roomCellObjectsRenderer.Draw(renderer);
		descriptorSelectorRenderer.Draw(renderer);
		GetUIContext().GetLayoutManager().GetDescriptor(LAYOUT_ROOM_VIEW_POSITION)->Draw(renderer);
		return false;
	}

	void EditNavigateRoomStateHandler::MoveCursor(const tggd::graphics::XY<int>& delta)
	{
		int newCursorX = (int)GetEditorContext().GetRoomView().GetCursor().GetX() + delta.GetX();
		int newCursorY = (int)GetEditorContext().GetRoomView().GetCursor().GetY() + delta.GetY();
		auto room = GetEditorContext().GetRoomList().GetRoom();
		newCursorX = tggd::common::Utility::PositiveModulo(newCursorX, room->GetColumns());
		newCursorY = tggd::common::Utility::PositiveModulo(newCursorY, room->GetRows());
		GetEditorContext().GetRoomView().SetCursor({ (size_t)newCursorX, (size_t)newCursorY });
		GetEditorContext().GetRoomCellObjects().Reset();
	}

	bool EditNavigateRoomStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
		case aspirant::commonui::Command::RED:
			SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
			break;
		case aspirant::commonui::Command::UP:
			MoveCursor({ 0,-1 });
			break;
		case aspirant::commonui::Command::DOWN:
			MoveCursor({ 0,1 });
			break;
		case aspirant::commonui::Command::LEFT:
			MoveCursor({ -1, 0 });
			break;
		case aspirant::commonui::Command::RIGHT:
			MoveCursor({ 1, 0 });
			break;
		case aspirant::commonui::Command::GREEN:
			PlaceObject();
			break;
		case aspirant::commonui::Command::NEXT:
			SetUIState(aspirant::commonui::UIState::EDIT_DESCRIPTOR_SELECTOR);
			break;
		}
		return true;
	}

	bool EditNavigateRoomStateHandler::OnUpdate(int)
	{
		auto& cursorPosition = GetEditorContext().GetRoomView().GetCursor();
		std::stringstream ss;
		ss << "(" << cursorPosition.GetX() << "," << cursorPosition.GetY() << ")";//TODO: magic string
		GetUIContext().GetStringManager().Set(TEXT_ROOM_VIEW_POSITION_NAME, ss.str());
		return false;
	}

	EditNavigateRoomStateHandler::EditNavigateRoomStateHandler
	(
		MessageHandler* parent,
		aspirant::editor::context::EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext,
		const aspirant::editor::controls::RoomRenderer& roomRenderer,
		const aspirant::editor::controls::RoomCellObjectsRenderer& roomCellObjectsRenderer,
		const aspirant::editor::controls::DescriptorSelectorRenderer& descriptorSelectorRenderer
	)
		: CommonRoomEditorStateHandler
		(
			parent, 
			aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, 
			LAYOUT_NAME, uiContext, 
			editorContext, 
			roomRenderer,
			roomCellObjectsRenderer,
			descriptorSelectorRenderer
		)
	{

	}

	void EditNavigateRoomStateHandler::PlaceObject()
	{
		auto& cursorPosition = GetEditorContext().GetRoomView().GetCursor();
		auto descriptor = GetEditorContext().GetDescriptorSelector().GetDescriptor(GetEditorContext().GetDescriptorSelector().GetIndex());
		auto roomCell = GetEditorContext().GetRoomList().GetRoom()->GetCell(cursorPosition.GetX(), cursorPosition.GetY());
		auto obj = descriptor->CreateObject();
		if (!roomCell->AddObject(obj))
		{
			delete obj;
		}
	}

}