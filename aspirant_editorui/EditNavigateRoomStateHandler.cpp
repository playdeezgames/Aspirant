#include "EditNavigateRoomStateHandler.h"
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";

	bool EditNavigateRoomStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		CommonEditorStateHandler::OnDraw(renderer);
		roomRenderer.Draw(renderer);
		return false;
	}


	bool EditNavigateRoomStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
		case aspirant::commonui::Command::RED:
			SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
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