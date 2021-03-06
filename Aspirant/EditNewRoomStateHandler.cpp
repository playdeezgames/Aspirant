#include "EditNewRoomStateHandler.h"
#include <sstream>
namespace aspirant
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
			GetEditorContext().AppendNewRoomName(text);
			return true;
		}
		return false;
	}

	void EditNewRoomStateHandler::CreateRoom()
	{
		GetEditorContext().GetScenario().AddRoom(GetEditorContext().GetNewRoomName(), GetEditorContext().GetNewRoomColumns(), GetEditorContext().GetNewRoomRows());
		GetEditorContext().SaveScenario();
	}


	void EditNewRoomStateHandler::ActivateItem(const NewRoomItem& item)
	{
		switch (item)
		{
		case NewRoomItem::CREATE:
			CreateRoom();
			GetEditorContext().UpdateRoomList();
			SetUIState(UIState::EDIT_PICK_ROOM);
			break;
		case NewRoomItem::CANCEL:
			SetUIState(UIState::EDIT_SCENARIO);
			break;
		}
	}

	EditNewRoomStateHandler::EditNewRoomStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const UIContext& uiContext
	)
		: EditorMenuStateHandler
		(
			parent,
			UIState::EDIT_NEW_ROOM,
			UIState::EDIT_SCENARIO,
			LAYOUT_NAME,
			NewRoomItem::CANCEL,
			uiContext,
			editorContext
		)
	{
		AddMenuItem(NewRoomItem::NAME, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROOM_NAME, NewRoomItem::CANCEL, NewRoomItem::COLUMNS));
		AddMenuItem(NewRoomItem::COLUMNS, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_COLUMNS, NewRoomItem::NAME, NewRoomItem::ROWS));
		AddMenuItem(NewRoomItem::ROWS, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROWS, NewRoomItem::COLUMNS, NewRoomItem::CREATE));
		AddMenuItem(NewRoomItem::CREATE, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CREATE, NewRoomItem::ROWS, NewRoomItem::CANCEL));
		AddMenuItem(NewRoomItem::CANCEL, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CANCEL, NewRoomItem::CREATE, NewRoomItem::NAME));
	}

	void EditNewRoomStateHandler::IncreaseItem(const NewRoomItem& item)
	{
		switch (item)
		{
		case NewRoomItem::COLUMNS:
			GetEditorContext().IncrementNewRoomColumns();
			break;
		case NewRoomItem::ROWS:
			GetEditorContext().IncrementNewRoomRows();
			break;
		}
	}

	void EditNewRoomStateHandler::DecreaseItem(const NewRoomItem& item)
	{
		switch (item)
		{
		case NewRoomItem::COLUMNS:
			GetEditorContext().DecrementNewRoomColumns();
			break;
		case NewRoomItem::ROWS:
			GetEditorContext().DecrementNewRoomRows();
			break;
		}
	}

	bool EditNewRoomStateHandler::OnUpdate()
	{
		GetUIContext().GetStringManager().Set(TEXT_NAME_ROOM_NAME, GetEditorContext().GetNewRoomName());

		std::stringstream ss;
		ss << GetEditorContext().GetNewRoomColumns();
		GetUIContext().GetStringManager().Set(TEXT_NAME_COLUMNS, ss.str());

		ss.str("");
		ss << GetEditorContext().GetNewRoomRows();
		GetUIContext().GetStringManager().Set(TEXT_NAME_ROWS, ss.str());

		return MenuStateHandler<NewRoomItem>::OnUpdate();
	}

	bool EditNewRoomStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::BACK:
			if (GetMenuItem() == NewRoomItem::NAME)
			{
				GetEditorContext().ClearNewRoomName();
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