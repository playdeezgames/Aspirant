#include "EditNavigateRoomStateHandler.h"
#include "Utility.h"
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";

	bool EditNavigateRoomStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		CommonEditorStateHandler::OnDraw(renderer);
		roomRenderer.Draw(renderer);
		return false;
	}

	void EditNavigateRoomStateHandler::MoveCursor(const tggd::graphics::XY<int>& delta)
	{
		int newCursorX = (int)GetEditorContext().GetRoomView().GetCursor().GetX() + delta.GetX();
		int newCursorY = (int)GetEditorContext().GetRoomView().GetCursor().GetY() + delta.GetY();
		auto room = GetEditorContext().GetRoom();
		newCursorX = tggd::common::Utility::PositiveModulo(newCursorX, room->GetColumns());
		newCursorY = tggd::common::Utility::PositiveModulo(newCursorY, room->GetRows());
		GetEditorContext().GetRoomView().SetCursor({ (size_t)newCursorX, (size_t)newCursorY });

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
		}
		return true;
	}

	bool EditNavigateRoomStateHandler::OnUpdate(int)
	{
		return false;
	}
	EditNavigateRoomStateHandler::EditNavigateRoomStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext,
		const RoomRenderer& roomRenderer
	)
		: CommonEditorStateHandler(parent, aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM, LAYOUT_NAME, uiContext, editorContext)
		, roomRenderer(roomRenderer)
	{

	}
}