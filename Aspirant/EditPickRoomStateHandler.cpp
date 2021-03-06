#include "EditPickRoomStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditPickRoom";
	const std::string TEXT_NAME_STRING_ROOM_NAME = "EditPickRoom.Text.RoomName";


	bool EditPickRoomStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::BACK:
		case Command::RED:
			SetUIState(UIState::EDIT_SCENARIO);
			break;
		case Command::RIGHT:
		case Command::NEXT:
			GetEditorContext().NextRoom();
			break;
		case Command::LEFT:
		case Command::PREVIOUS:
			GetEditorContext().PreviousRoom();
			break;
		case Command::GREEN:
			SetUIState(UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
		return true;
	}

	bool EditPickRoomStateHandler::OnUpdate(int)
	{
		if (GetEditorContext().GetRoomCount() > 0)
		{
			auto& roomName = GetEditorContext().GetRoomList()[GetEditorContext().GetRoomIndex()];
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
		const UIContext& uiContext
	)
		: CommonEditorStateHandler(parent, UIState::EDIT_PICK_ROOM, LAYOUT_NAME, uiContext, editorContext)
	{

	}

}