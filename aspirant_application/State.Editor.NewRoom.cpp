#include "Application.h"
#include "Graphics.Layouts.h"
#include <sstream>
#include "Context.Editor.NewRoom.h"
#include "Context.Editor.Rooms.h"
#include "Context.Editor.Scenario.h"
#include "Application.Command.h"
#include "Application.TextInput.h"
#include "Application.Update.h"
namespace state::editor::NewRoom
{
	const std::string LAYOUT_NAME = "State.Editor.NewRoom";
	const std::string MENU_ID = "NewRoom";
	const std::string ROOM_NAME_TEXT_ID = "RoomName";
	const std::string COLUMNS_TEXT_ID = "Columns";
	const std::string ROWS_TEXT_ID = "Rows";
	const std::string TERRAIN_TEXT_ID = "Terrain";

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
		graphics::Layouts::SetTextText(LAYOUT_NAME, ROOM_NAME_TEXT_ID, ::context::editor::NewRoom::GetName());

		std::stringstream ss;
		ss << ::context::editor::NewRoom::GetColumns();
		graphics::Layouts::SetTextText(LAYOUT_NAME, COLUMNS_TEXT_ID, ss.str());

		ss.str("");
		ss << ::context::editor::NewRoom::GetRows();
		graphics::Layouts::SetTextText(LAYOUT_NAME, ROWS_TEXT_ID, ss.str());

		graphics::Layouts::SetTextText(LAYOUT_NAME, TERRAIN_TEXT_ID, ::context::editor::NewRoom::GetTerrain());
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
		::application::Command::SetHandler(::UIState::EDIT_NEW_ROOM, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_NEW_ROOM, LAYOUT_NAME);
		::application::Update::AddHandler(::UIState::EDIT_NEW_ROOM, OnUpdate);
		::application::TextInput::SetHandler(::UIState::EDIT_NEW_ROOM, OnTextInput);
	}
}
