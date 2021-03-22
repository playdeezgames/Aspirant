#include "EditPickRoomStateHandler.h"
#include "SplashStateHandler.h"
#include "AspirantApplication.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "EditorRoomListContext.h"
#include "StringManager.h"
#include "EditorRoomViewContext.h"
namespace aspirant::editorui::EditPickRoomStateHandler
{
	const std::string LAYOUT_NAME = "EditPickRoom";
	const std::string TEXT_NAME_STRING_ROOM_NAME = "EditPickRoom.Text.RoomName";

	static void OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		case aspirant::commonui::Command::RIGHT:
		case aspirant::commonui::Command::NEXT:
			aspirant::editor::context::EditorRoomListContext::NextRoom();
			break;
		case aspirant::commonui::Command::LEFT:
		case aspirant::commonui::Command::PREVIOUS:
			aspirant::editor::context::EditorRoomListContext::PreviousRoom();
			break;
		case aspirant::commonui::Command::GREEN:
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
			tggd::data::StringManager::Set(TEXT_NAME_STRING_ROOM_NAME, roomName);
		}
		else
		{
			tggd::data::StringManager::Set(TEXT_NAME_STRING_ROOM_NAME, "-");
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::EDIT_PICK_ROOM, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::EDIT_PICK_ROOM, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::EDIT_PICK_ROOM, OnUpdate);
	}
}
