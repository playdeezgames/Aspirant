#include "Aspirant.State.Editor.NewRoom.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "MenuItem.h"
#include <sstream>
#include "Data.Strings.h"
#include "Aspirant.Context.Editor.Scenario.h"
#include "Aspirant.Context.Editor.NewRoom.h"
#include "Aspirant.Context.Editor.Rooms.h"
namespace aspirant::state::editor::NewRoom
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
	static std::map<NewRoomItem, ::MenuItem<NewRoomItem>> items;

	static void CreateRoom()
	{
		aspirant::context::editor::Scenario::Get().AddRoom
		(
			aspirant::context::editor::NewRoom::GetName(),
			aspirant::context::editor::NewRoom::GetColumns(),
			aspirant::context::editor::NewRoom::GetRows(),
			aspirant::context::editor::NewRoom::GetTerrain()
		);
		aspirant::context::editor::Scenario::Save();
	}


	static void ActivateItem()
	{
		switch (current)
		{
		case NewRoomItem::CREATE:
			CreateRoom();
			aspirant::context::editor::Rooms::UpdateRoomList();
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
			aspirant::context::editor::NewRoom::NextTerrain();
			break;
		case NewRoomItem::COLUMNS:
			aspirant::context::editor::NewRoom::IncrementColumns();
			break;
		case NewRoomItem::ROWS:
			aspirant::context::editor::NewRoom::IncrementRows();
			break;
		}
	}

	void DecreaseItem()
	{
		switch (current)
		{
		case NewRoomItem::TERRAIN:
			aspirant::context::editor::NewRoom::PreviousTerrain();
			break;

		case NewRoomItem::COLUMNS:
			aspirant::context::editor::NewRoom::DecrementColumns();
			break;

		case NewRoomItem::ROWS:
			aspirant::context::editor::NewRoom::DecrementRows();
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
				aspirant::context::editor::NewRoom::AppendName("\b");
			}
			else
			{
				::Application::SetUIState(::UIState::EDIT_SCENARIO);
			}
			break;
		case ::Command::RED:
			if (current == NewRoomItem::NAME)
			{
				aspirant::context::editor::NewRoom::ClearName();
			}
			break;
		case ::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case ::Command::DOWN:
			current = items[current].GetNextMenuItem();
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
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}

		::data::Strings::Set(TEXT_NAME_ROOM_NAME, aspirant::context::editor::NewRoom::GetName());

		std::stringstream ss;
		ss << aspirant::context::editor::NewRoom::GetColumns();
		::data::Strings::Set(TEXT_NAME_COLUMNS, ss.str());

		ss.str("");
		ss << aspirant::context::editor::NewRoom::GetRows();
		::data::Strings::Set(TEXT_NAME_ROWS, ss.str());

		data::Strings::Set(TEXT_NAME_TERRAIN, aspirant::context::editor::NewRoom::GetTerrain());
	}

	static void OnTextInput(const std::string& text)
	{
		if (current == NewRoomItem::NAME)
		{
			aspirant::context::editor::NewRoom::AppendName(text);
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_NEW_ROOM, OnCommand);
		::Application::SetRenderHandler(::UIState::EDIT_NEW_ROOM, OnDraw);
		::Application::SetUpdateHandler(::UIState::EDIT_NEW_ROOM, OnUpdate);
		::Application::SetTextInputHandler(::UIState::EDIT_NEW_ROOM, OnTextInput);
		items[NewRoomItem::NAME] = ::MenuItem<NewRoomItem>(COLOR_NAME_ROOM_NAME, NewRoomItem::CANCEL, NewRoomItem::COLUMNS);
		items[NewRoomItem::COLUMNS] = ::MenuItem<NewRoomItem>(COLOR_NAME_COLUMNS, NewRoomItem::NAME, NewRoomItem::ROWS);
		items[NewRoomItem::ROWS] = ::MenuItem<NewRoomItem>(COLOR_NAME_ROWS, NewRoomItem::COLUMNS, NewRoomItem::TERRAIN);
		items[NewRoomItem::TERRAIN] = ::MenuItem<NewRoomItem>(COLOR_NAME_TERRAIN, NewRoomItem::ROWS, NewRoomItem::CREATE);
		items[NewRoomItem::CREATE] = ::MenuItem<NewRoomItem>(COLOR_NAME_CREATE, NewRoomItem::TERRAIN, NewRoomItem::CANCEL);
		items[NewRoomItem::CANCEL] = ::MenuItem<NewRoomItem>(COLOR_NAME_CANCEL, NewRoomItem::CREATE, NewRoomItem::NAME);
	}
}
