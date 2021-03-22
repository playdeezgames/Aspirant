#include "EditNewRoomStateHandler.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "MenuItemDescriptor.h"
#include <sstream>
#include "Data.Strings.h"
#include "EditorContext.h"
#include "EditorNewRoomContext.h"
#include "EditorRoomListContext.h"
namespace aspirant::editorui::EditNewRoomStateHandler
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

	enum class NewRoomItem
	{
		NAME,
		COLUMNS,
		ROWS,
		CREATE,
		CANCEL
	};
	static NewRoomItem current = NewRoomItem::CANCEL;
	static std::map<NewRoomItem, aspirant::commonui::MenuItemDescriptor<NewRoomItem>> items;

	static void CreateRoom()
	{
		aspirant::editor::context::EditorContext::GetScenario().AddRoom(aspirant::editor::context::EditorNewRoomContext::GetNewRoomName(), aspirant::editor::context::EditorNewRoomContext::GetNewRoomColumns(), aspirant::editor::context::EditorNewRoomContext::GetNewRoomRows());
		aspirant::editor::context::EditorContext::SaveScenario();
	}


	static void ActivateItem()
	{
		switch (current)
		{
		case NewRoomItem::CREATE:
			CreateRoom();
			aspirant::editor::context::EditorRoomListContext::UpdateRoomList();
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
			break;
		case NewRoomItem::CANCEL:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		}
	}

	void IncreaseItem()
	{
		switch (current)
		{
		case NewRoomItem::COLUMNS:
			aspirant::editor::context::EditorNewRoomContext::IncrementNewRoomColumns();
			break;
		case NewRoomItem::ROWS:
			aspirant::editor::context::EditorNewRoomContext::IncrementNewRoomRows();
			break;
		}
	}

	void DecreaseItem()
	{
		switch (current)
		{
		case NewRoomItem::COLUMNS:
			aspirant::editor::context::EditorNewRoomContext::DecrementNewRoomColumns();
			break;

		case NewRoomItem::ROWS:
			aspirant::editor::context::EditorNewRoomContext::DecrementNewRoomRows();
			break;
		}
	}

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::BACK:
			if (current == NewRoomItem::NAME)
			{
				aspirant::editor::context::EditorNewRoomContext::ClearNewRoomName();
			}
			else
			{
				aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			}
			break;
		case aspirant::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case aspirant::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case aspirant::Command::LEFT:
			DecreaseItem();
			break;
		case aspirant::Command::RIGHT:
			IncreaseItem();
			break;
		case aspirant::Command::GREEN:
			ActivateItem();
			break;
		}

	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		for (auto& item : items)
		{
			tggd::data::StringManager::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}

		tggd::data::StringManager::Set(TEXT_NAME_ROOM_NAME, aspirant::editor::context::EditorNewRoomContext::GetNewRoomName());

		std::stringstream ss;
		ss << aspirant::editor::context::EditorNewRoomContext::GetNewRoomColumns();
		tggd::data::StringManager::Set(TEXT_NAME_COLUMNS, ss.str());

		ss.str("");
		ss << aspirant::editor::context::EditorNewRoomContext::GetNewRoomRows();
		tggd::data::StringManager::Set(TEXT_NAME_ROWS, ss.str());
	}

	static void OnTextInput(const std::string& text)
	{
		aspirant::editor::context::EditorNewRoomContext::AppendNewRoomName(text);
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::EDIT_NEW_ROOM, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::EDIT_NEW_ROOM, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::EDIT_NEW_ROOM, OnUpdate);
		aspirant::Application::SetTextInputHandler(aspirant::commonui::UIState::EDIT_NEW_ROOM, OnTextInput);
		items[NewRoomItem::NAME] = aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROOM_NAME, NewRoomItem::CANCEL, NewRoomItem::COLUMNS);
		items[NewRoomItem::COLUMNS] = aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_COLUMNS, NewRoomItem::NAME, NewRoomItem::ROWS);
		items[NewRoomItem::ROWS] = aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_ROWS, NewRoomItem::COLUMNS, NewRoomItem::CREATE);
		items[NewRoomItem::CREATE] = aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CREATE, NewRoomItem::ROWS, NewRoomItem::CANCEL);
		items[NewRoomItem::CANCEL]= aspirant::commonui::MenuItemDescriptor<NewRoomItem>(COLOR_NAME_CANCEL, NewRoomItem::CREATE, NewRoomItem::NAME);
	}
}
