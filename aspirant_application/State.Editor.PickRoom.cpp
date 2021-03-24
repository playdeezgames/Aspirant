#include "Aspirant.State.Editor.PickRoom.h"
#include "Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
#include "Aspirant.Context.Editor.Rooms.h"
#include "Data.Strings.h"
#include "Aspirant.Context.Editor.RoomView.h"
namespace aspirant::state::editor::PickRoom
{
	const std::string LAYOUT_NAME = "EditPickRoom";
	const std::string TEXT_NAME_STRING_ROOM_NAME = "EditPickRoom.Text.RoomName";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO);
			break;
		case ::Command::RIGHT:
		case ::Command::NEXT:
			aspirant::context::editor::Rooms::NextRoom();
			break;
		case ::Command::LEFT:
		case ::Command::PREVIOUS:
			aspirant::context::editor::Rooms::PreviousRoom();
			break;
		case ::Command::GREEN:
			aspirant::context::editor::RoomView::SetCursor({ 0,0 });
			::Application::SetUIState(aspirant::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		if (aspirant::context::editor::Rooms::GetRoomCount() > 0)
		{
			auto& roomName = aspirant::context::editor::Rooms::GetRoomList()[aspirant::context::editor::Rooms::GetRoomIndex()];
			::data::Strings::Set(TEXT_NAME_STRING_ROOM_NAME, roomName);
		}
		else
		{
			::data::Strings::Set(TEXT_NAME_STRING_ROOM_NAME, "-");
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(aspirant::UIState::EDIT_PICK_ROOM, OnCommand);
		::Application::SetRenderHandler(aspirant::UIState::EDIT_PICK_ROOM, OnDraw);
		::Application::SetUpdateHandler(aspirant::UIState::EDIT_PICK_ROOM, OnUpdate);
	}
}
