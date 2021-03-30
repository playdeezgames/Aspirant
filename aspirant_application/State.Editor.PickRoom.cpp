#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Context.Editor.Rooms.h"
#include "Context.Editor.RoomView.h"
#include "Application.Command.h"
#include "Application.Update.h"
#include "Application.UIState.h"
namespace state::editor::PickRoom
{
	const std::string LAYOUT_NAME = "State.Editor.PickRoom";
	const std::string ROOM_NAME_TEXT_ID = "RoomName";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::application::UIState::Write(::UIState::EDIT_SCENARIO);
			break;
		case ::Command::RIGHT:
		case ::Command::NEXT:
			::context::editor::Rooms::NextRoom();
			break;
		case ::Command::LEFT:
		case ::Command::PREVIOUS:
			::context::editor::Rooms::PreviousRoom();
			break;
		case ::Command::GREEN:
			::context::editor::RoomView::SetCursor({ 0,0 });
			::application::UIState::Write(::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
		if (::context::editor::Rooms::GetRoomCount() > 0)
		{
			auto& roomName = ::context::editor::Rooms::GetRoomList()[::context::editor::Rooms::GetRoomIndex()];
			graphics::Layouts::SetTextText(LAYOUT_NAME, ROOM_NAME_TEXT_ID, roomName);
		}
		else
		{
			graphics::Layouts::SetTextText(LAYOUT_NAME, ROOM_NAME_TEXT_ID, "-");
		}
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::EDIT_PICK_ROOM, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_PICK_ROOM, LAYOUT_NAME);
		::application::Update::AddHandler(::UIState::EDIT_PICK_ROOM, OnUpdate);
	}
}
