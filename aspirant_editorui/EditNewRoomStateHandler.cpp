#include "EditNewRoomStateHandler.h"
#include <sstream>
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditNewRoom";

	const std::string COLOR_NAME_ROOM_NAME = "EditNewRoom.Color.RoomName";
	const std::string COLOR_NAME_COLUMNS = "EditNewRoom.Color.Columns";
	const std::string COLOR_NAME_ROWS = "EditNewRoom.Color.Rows";
	const std::string COLOR_NAME_CREATE = "EditNewRoom.Color.Create";
	const std::string COLOR_NAME_CANCEL = "EditNewRoom.Color.Cancel";

	const std::string TEXT_NAME_ROOM_NAME = "EditNewRoom.Text.RoomName";
	const std::string TEXT_NAME_COLUMNS = "EditNewRoom.Text.Columns";
	const std::string TEXT_NAME_ROWS = "EditNewRoom.Text.Rows";


	bool EditNewRoomStateHandler::OnText(const std::string& text)
	{
		if (GetMenuItem() == NewRoomItem::NAME)
		{
			GetEditorContext().GetNewRoom().AppendNewRoomName(text);
			return true;
		}
		return false;
	}

	void EditNewRoomStateHandler::CreateRoom()
	{
		GetEditorContext().GetScenario().AddRoom(GetEditorContext().GetNewRoom().GetNewRoomName(), GetEditorContext().GetNewRoom().GetNewRoomColumns(), GetEditorContext().GetNewRoom().GetNewRoomRows());
		GetEditorContext().SaveScenario();
	}


	void EditNewRoomStateHandler::ActivateItem(const NewRoomItem& item)
	{
		switch (item)
		{
		case NewRoomItem::CREATE:
			CreateRoom();
			GetEditorContext().GetRoomList().UpdateRoomList();
			SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
			break;
		case NewRoomItem::CANCEL:
			SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		}
	}

	EditNewRoomStateHandler::EditNewRoomStateHandler
	(
		MessageHandler* parent,
		aspirant::editor::context::EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext
	)
		: EditorMenuStateHandler
		(
			parent,
			aspirant::commonui::UIState::EDIT_NEW_ROOM,
			aspirant::commonui::UIState::EDIT_SCENARIO,
			LAYOUT_NAME,
			NewRoomItem::CANCEL,
			uiContext,
			editorContext
		)
	{
		AddMenuItem(NewRoomItem::NAME, aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROOM_NAME, NewRoomItem::CANCEL, NewRoomItem::COLUMNS));
		AddMenuItem(NewRoomItem::COLUMNS, aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_COLUMNS, NewRoomItem::NAME, NewRoomItem::ROWS));
		AddMenuItem(NewRoomItem::ROWS, aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROWS, NewRoomItem::COLUMNS, NewRoomItem::CREATE));
		AddMenuItem(NewRoomItem::CREATE, aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CREATE, NewRoomItem::ROWS, NewRoomItem::CANCEL));
		AddMenuItem(NewRoomItem::CANCEL, aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CANCEL, NewRoomItem::CREATE, NewRoomItem::NAME));
	}

	void EditNewRoomStateHandler::IncreaseItem(const NewRoomItem& item)
	{
		switch (item)
		{
		case NewRoomItem::COLUMNS:
			GetEditorContext().GetNewRoom().IncrementNewRoomColumns();
			break;
		case NewRoomItem::ROWS:
			GetEditorContext().GetNewRoom().IncrementNewRoomRows();
			break;
		}
	}

	void EditNewRoomStateHandler::DecreaseItem(const NewRoomItem& item)
	{
		switch (item)
		{
		case NewRoomItem::COLUMNS:
			GetEditorContext().GetNewRoom().DecrementNewRoomColumns();
			break;
		case NewRoomItem::ROWS:
			GetEditorContext().GetNewRoom().DecrementNewRoomRows();
			break;
		}
	}

	bool EditNewRoomStateHandler::OnUpdate()
	{
		GetUIContext().GetStringManager().Set(TEXT_NAME_ROOM_NAME, GetEditorContext().GetNewRoom().GetNewRoomName());

		std::stringstream ss;
		ss << GetEditorContext().GetNewRoom().GetNewRoomColumns();
		GetUIContext().GetStringManager().Set(TEXT_NAME_COLUMNS, ss.str());

		ss.str("");
		ss << GetEditorContext().GetNewRoom().GetNewRoomRows();
		GetUIContext().GetStringManager().Set(TEXT_NAME_ROWS, ss.str());

		return MenuStateHandler<NewRoomItem>::OnUpdate();
	}

	bool EditNewRoomStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
			if (GetMenuItem() == NewRoomItem::NAME)
			{
				GetEditorContext().GetNewRoom().ClearNewRoomName();
				return true;
			}
			else
			{
				return MenuStateHandler<NewRoomItem>::OnCommand(command);
			}
		default:
			return MenuStateHandler<NewRoomItem>::OnCommand(command);
		}
	}


}