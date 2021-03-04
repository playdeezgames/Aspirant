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
		const UIState& uiState,
		tggd::common::LayoutManager& layoutManager,
		EditorContext& editorContext,
		tggd::common::StringManager& stringManager
	)
		: CommonStateHandler(parent, uiState, UIState::EDIT_PICK_ROOM, layoutManager.GetDescriptor(LAYOUT_NAME))
	{

	}

}