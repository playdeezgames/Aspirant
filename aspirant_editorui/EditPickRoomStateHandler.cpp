#include "EditPickRoomStateHandler.h"
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditPickRoom";
	const std::string TEXT_NAME_STRING_ROOM_NAME = "EditPickRoom.Text.RoomName";


	bool EditPickRoomStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
		case aspirant::commonui::Command::RED:
			SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		case aspirant::commonui::Command::RIGHT:
		case aspirant::commonui::Command::NEXT:
			GetEditorContext().GetRoomList().NextRoom();
			break;
		case aspirant::commonui::Command::LEFT:
		case aspirant::commonui::Command::PREVIOUS:
			GetEditorContext().GetRoomList().PreviousRoom();
			break;
		case aspirant::commonui::Command::GREEN:
			GetEditorContext().GetRoomView().SetCursor({ 0,0 });
			SetUIState(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
		return true;
	}

	bool EditPickRoomStateHandler::OnUpdate(int)
	{
		if (GetEditorContext().GetRoomList().GetRoomCount() > 0)
		{
			auto& roomName = GetEditorContext().GetRoomList().GetRoomList()[GetEditorContext().GetRoomList().GetRoomIndex()];
			GetUIContext().GetStringManager().Set(TEXT_NAME_STRING_ROOM_NAME, roomName);
		}
		else
		{
			GetUIContext().GetStringManager().Set(TEXT_NAME_STRING_ROOM_NAME, "-");
		}
		return false;
	}

	EditPickRoomStateHandler::EditPickRoomStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext
	)
		: CommonEditorStateHandler(parent, aspirant::commonui::UIState::EDIT_PICK_ROOM, LAYOUT_NAME, uiContext, editorContext)
	{

	}

}