#include "EditPickRoomStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditPickRoom";

	bool EditPickRoomStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::BACK:
		case Command::RED:
			SetUIState(UIState::EDIT_SCENARIO);
			break;
		}
		return true;
	}

	bool EditPickRoomStateHandler::OnUpdate(int)
	{
		return false;
	}

	EditPickRoomStateHandler::EditPickRoomStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		tggd::common::StringManager& stringManager,
		const UIContext& uiContext
	)
		: CommonStateHandler(parent, UIState::EDIT_PICK_ROOM, LAYOUT_NAME, uiContext)
	{

	}

}