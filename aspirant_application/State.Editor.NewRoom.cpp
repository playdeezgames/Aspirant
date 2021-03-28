#include "State.Editor.NewRoom.h"
#include "Application.h"
#include "Graphics.Layouts.h"
#include <sstream>
#include "Data.Strings.h"
#include "Context.Editor.NewRoom.h"
#include "Context.Editor.Rooms.h"
#include "Context.Editor.Scenario.h"
namespace state::editor::NewRoom
{
	const std::string LAYOUT_NAME = "State.Editor.NewRoom";
	const std::string MENU_ID = "NewRoom";
	const std::string TEXT_NAME_ROOM_NAME = "EditNewRoom.Text.RoomName";
	const std::string TEXT_NAME_COLUMNS = "EditNewRoom.Text.Columns";
	const std::string TEXT_NAME_ROWS = "EditNewRoom.Text.Rows";
	const std::string TEXT_NAME_TERRAIN = "EditNewRoom.Text.Terrain";

	enum class NewRoomItem
	{
		NAME,
		COLUMNS,
		ROWS,
		TERRAIN,
		CREATE,
		CANCEL
	};

	static void CreateRoom()
	{
		::context::editor::Scenario::Get().AddRoom
		(
			::context::editor::NewRoom::GetName(),
			::context::editor::NewRoom::GetColumns(),
			::context::editor::NewRoom::GetRows(),
			::context::editor::NewRoom::GetTerrain()
		);
		::context::editor::Scenario::Save();
	}

	static NewRoomItem GetCurrentItem()
	{
		return (NewRoomItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME, MENU_ID).value();
	}

	static void ActivateItem()
	{
		switch (GetCurrentItem())
		{
		case NewRoomItem::CREATE:
			CreateRoom();
			::context::editor::Rooms::UpdateRoomList();
			::Application::SetUIState(::UIState::EDIT_PICK_ROOM);
			break;
		case NewRoomItem::CANCEL:
			::Application::SetUIState(::UIState::EDIT_SCENARIO);
			break;
		}
	}

	void IncreaseItem()
	{
		switch (GetCurrentItem())
		{
		case NewRoomItem::TERRAIN:
			::context::editor::NewRoom::NextTerrain();
			break;
		case NewRoomItem::COLUMNS:
			::context::editor::NewRoom::IncrementColumns();
			break;
		case NewRoomItem::ROWS:
			::context::editor::NewRoom::IncrementRows();
			break;
		}
	}

	void DecreaseItem()
	{
		switch (GetCurrentItem())
		{
		case NewRoomItem::TERRAIN:
			::context::editor::NewRoom::PreviousTerrain();
			break;

		case NewRoomItem::COLUMNS:
			::context::editor::NewRoom::DecrementColumns();
			break;

		case NewRoomItem::ROWS:
			::context::editor::NewRoom::DecrementRows();
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			if (GetCurrentItem() == NewRoomItem::NAME)
			{
				::context::editor::NewRoom::AppendName("\b");
			}
			else
			{
				::Application::SetUIState(::UIState::EDIT_SCENARIO);
			}
			break;
		case ::Command::RED:
			if (GetCurrentItem() == NewRoomItem::NAME)
			{
				::context::editor::NewRoom::ClearName();
			}
			break;
		case ::Command::UP:
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::LEFT:
			DecreaseItem();
			break;
		case ::Command::RIGHT:
			IncreaseItem();
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
		::data::Strings::Set(TEXT_NAME_ROOM_NAME, ::context::editor::NewRoom::GetName());

		std::stringstream ss;
		ss << ::context::editor::NewRoom::GetColumns();
		::data::Strings::Set(TEXT_NAME_COLUMNS, ss.str());

		ss.str("");
		ss << ::context::editor::NewRoom::GetRows();
		::data::Strings::Set(TEXT_NAME_ROWS, ss.str());

		data::Strings::Set(TEXT_NAME_TERRAIN, ::context::editor::NewRoom::GetTerrain());
	}

	static void OnTextInput(const std::string& text)
	{
		if (GetCurrentItem() == NewRoomItem::NAME)
		{
			::context::editor::NewRoom::AppendName(text);
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_NEW_ROOM, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_NEW_ROOM, LAYOUT_NAME);
		::Application::SetUpdateHandler(::UIState::EDIT_NEW_ROOM, OnUpdate);
		::Application::SetTextInputHandler(::UIState::EDIT_NEW_ROOM, OnTextInput);
	}
}
