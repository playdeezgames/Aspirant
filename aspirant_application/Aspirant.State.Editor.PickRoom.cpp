#include "Aspirant.State.Editor.PickRoom.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
#include "Aspirant.Context.Editor.Rooms.h"
#include "Data.Strings.h"
#include "Aspirant.Context.Editor.RoomView.h"
namespace aspirant::state::editor::PickRoom
{
	const std::string LAYOUT_NAME = "EditPickRoom";
	const std::string TEXT_NAME_STRING_ROOM_NAME = "EditPickRoom.Text.RoomName";

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO);
			break;
		case aspirant::Command::RIGHT:
		case aspirant::Command::NEXT:
			aspirant::context::editor::Rooms::NextRoom();
			break;
		case aspirant::Command::LEFT:
		case aspirant::Command::PREVIOUS:
			aspirant::context::editor::Rooms::PreviousRoom();
			break;
		case aspirant::Command::GREEN:
			aspirant::context::editor::RoomView::SetCursor({ 0,0 });
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_NAVIGATE_ROOM);
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
		aspirant::Application::SetCommandHandler(aspirant::UIState::EDIT_PICK_ROOM, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::EDIT_PICK_ROOM, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::EDIT_PICK_ROOM, OnUpdate);
	}
}
