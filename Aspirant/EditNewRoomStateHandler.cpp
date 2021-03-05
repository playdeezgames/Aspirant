#include "EditNewRoomStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditNewRoom";

	const std::string COLOR_NAME_ROOM_NAME = "EditNewRoom.Color.RoomName";
	const std::string COLOR_NAME_COLUMNS = "EditNewRoom.Color.Columns";
	const std::string COLOR_NAME_ROWS = "EditNewRoom.Color.Rows";
	const std::string COLOR_NAME_CREATE = "EditNewRoom.Color.Create";
	const std::string COLOR_NAME_CANCEL = "EditNewRoom.Color.Cancel";


	bool EditNewRoomStateHandler::OnText(const std::string& text)
	{
		return false;
	}

	void EditNewRoomStateHandler::ActivateItem(const NewRoomItem& item)
	{

	}

	EditNewRoomStateHandler::EditNewRoomStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const UIContext& uiContext
	)
		: MenuStateHandler
		(
			parent,
			UIState::EDIT_NEW_ROOM,
			UIState::EDIT_SCENARIO,
			LAYOUT_NAME,
			NewRoomItem::CANCEL,
			uiContext
		)
		, editorContext(editorContext)
	{
		AddMenuItem(NewRoomItem::NAME, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROOM_NAME, NewRoomItem::CANCEL, NewRoomItem::COLUMNS));
		AddMenuItem(NewRoomItem::COLUMNS, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_COLUMNS, NewRoomItem::NAME, NewRoomItem::ROWS));
		AddMenuItem(NewRoomItem::ROWS, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROWS, NewRoomItem::COLUMNS, NewRoomItem::CREATE));
		AddMenuItem(NewRoomItem::CREATE, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CREATE, NewRoomItem::ROWS, NewRoomItem::CANCEL));
		AddMenuItem(NewRoomItem::CANCEL, MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CANCEL, NewRoomItem::CREATE, NewRoomItem::NAME));
	}

	void EditNewRoomStateHandler::IncreaseItem(const NewRoomItem&)
	{

	}

	void EditNewRoomStateHandler::DecreaseItem(const NewRoomItem&)
	{

	}
}