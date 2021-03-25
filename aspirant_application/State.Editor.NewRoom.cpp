#include "State.Editor.NewRoom.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "MenuItem.h"
#include <sstream>
#include "Data.Strings.h"
#include "Context.Editor.Scenario.h"
#include "Context.Editor.NewRoom.h"
#include "Context.Editor.Rooms.h"
namespace state::editor::NewRoom
{
	const std::string LAYOUT_NAME = "EditNewRoom";

	const std::string COLOR_NAME_ROOM_NAME = "EditNewRoom.Color.RoomName";
	const std::string COLOR_NAME_COLUMNS = "EditNewRoom.Color.Columns";
	const std::string COLOR_NAME_ROWS = "EditNewRoom.Color.Rows";
	const std::string COLOR_NAME_CREATE = "EditNewRoom.Color.Create";
	const std::string COLOR_NAME_CANCEL = "EditNewRoom.Color.Cancel";
	const std::string COLOR_NAME_TERRAIN = "EditNewRoom.Color.Terrain";

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
	static NewRoomItem current = NewRoomItem::CANCEL;
	static std::map<NewRoomItem, ::MenuItem<NewRoomItem>> items = 
	{
		{NewRoomItem::NAME, ::MenuItem<NewRoomItem>(COLOR_NAME_ROOM_NAME, NewRoomItem::CANCEL, NewRoomItem::COLUMNS)},
		{NewRoomItem::COLUMNS, ::MenuItem<NewRoomItem>(COLOR_NAME_COLUMNS, NewRoomItem::NAME, NewRoomItem::ROWS)},
		{NewRoomItem::ROWS, ::MenuItem<NewRoomItem>(COLOR_NAME_ROWS, NewRoomItem::COLUMNS, NewRoomItem::TERRAIN)},
		{NewRoomItem::TERRAIN, ::MenuItem<NewRoomItem>(COLOR_NAME_TERRAIN, NewRoomItem::ROWS, NewRoomItem::CREATE)},
		{NewRoomItem::CREATE, ::MenuItem<NewRoomItem>(COLOR_NAME_CREATE, NewRoomItem::TERRAIN, NewRoomItem::CANCEL)},
		{NewRoomItem::CANCEL, ::MenuItem<NewRoomItem>(COLOR_NAME_CANCEL, NewRoomItem::CREATE, NewRoomItem::NAME)}
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


	static void ActivateItem()
	{
		switch (current)
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
		switch (current)
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
		switch (current)
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
			if (current == NewRoomItem::NAME)
			{
				::context::editor::NewRoom::AppendName("\b");
			}
			else
			{
				::Application::SetUIState(::UIState::EDIT_SCENARIO);
			}
			break;
		case ::Command::RED:
			if (current == NewRoomItem::NAME)
			{
				::context::editor::NewRoom::ClearName();
			}
			break;
		case ::Command::UP:
			MenuItem<NewRoomItem>::Previous(current, items);
			break;
		case ::Command::DOWN:
			MenuItem<NewRoomItem>::Next(current, items);
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

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		MenuItem<NewRoomItem>::Update(items, current);

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
		if (current == NewRoomItem::NAME)
		{
			::context::editor::NewRoom::AppendName(text);
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_NEW_ROOM, OnCommand);
		::Application::SetRenderHandler(::UIState::EDIT_NEW_ROOM, OnDraw);
		::Application::SetUpdateHandler(::UIState::EDIT_NEW_ROOM, OnUpdate);
		::Application::SetTextInputHandler(::UIState::EDIT_NEW_ROOM, OnTextInput);
	}
}
