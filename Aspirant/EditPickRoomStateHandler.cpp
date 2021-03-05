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
			editorContext.NextRoom();
			break;
		case Command::LEFT:
		case Command::PREVIOUS:
			editorContext.PreviousRoom();
			break;
		}
		return true;
	}

	bool EditPickRoomStateHandler::OnUpdate(int)
	{
		if (editorContext.GetRoomCount() > 0)
		{
			auto& roomName = editorContext.GetRoomList()[editorContext.GetRoomIndex()];
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
		: CommonStateHandler(parent, UIState::EDIT_PICK_ROOM, LAYOUT_NAME, uiContext)
		, editorContext(editorContext)
	{

	}

}