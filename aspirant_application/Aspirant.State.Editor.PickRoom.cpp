#include "Aspirant.State.Editor.PickRoom.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "EditorRoomListContext.h"
#include "Data.Strings.h"
#include "EditorRoomViewContext.h"
namespace aspirant::state::editor::PickRoom
{
	const std::string LAYOUT_NAME = "EditPickRoom";
	const std::string TEXT_NAME_STRING_ROOM_NAME = "EditPickRoom.Text.RoomName";

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		case aspirant::Command::RIGHT:
		case aspirant::Command::NEXT:
			aspirant::editor::context::EditorRoomListContext::NextRoom();
			break;
		case aspirant::Command::LEFT:
		case aspirant::Command::PREVIOUS:
			aspirant::editor::context::EditorRoomListContext::PreviousRoom();
			break;
		case aspirant::Command::GREEN:
			aspirant::editor::context::EditorRoomViewContext::SetCursor({ 0,0 });
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		if (aspirant::editor::context::EditorRoomListContext::GetRoomCount() > 0)
		{
			auto& roomName = aspirant::editor::context::EditorRoomListContext::GetRoomList()[aspirant::editor::context::EditorRoomListContext::GetRoomIndex()];
			::data::Strings::Set(TEXT_NAME_STRING_ROOM_NAME, roomName);
		}
		else
		{
			::data::Strings::Set(TEXT_NAME_STRING_ROOM_NAME, "-");
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::EDIT_PICK_ROOM, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::EDIT_PICK_ROOM, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::EDIT_PICK_ROOM, OnUpdate);
	}
}
