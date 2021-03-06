#include "EditNavigateRoomStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditNavigateRoom";

	bool EditNavigateRoomStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::BACK:
		case Command::RED:
			SetUIState(UIState::EDIT_PICK_ROOM);
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
		const UIContext& uiContext
	)
		: CommonStateHandler(parent, UIState::EDIT_NAVIGATE_ROOM, LAYOUT_NAME, uiContext)
		, editorContext(editorContext)
	{

	}
}