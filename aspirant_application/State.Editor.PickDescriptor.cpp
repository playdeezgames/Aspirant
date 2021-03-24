#include "Aspirant.State.Editor.PickDescriptor.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Renderer.Editor.Room.h"
#include "Renderer.Editor.Cell.h"
#include "Renderer.Editor.PickDescriptor.h"
#include "Common.Utility.h"
#include "Aspirant.Context.Editor.PickDescriptor.h"
namespace aspirant::state::editor::PickDescriptor
{
	const std::string LAYOUT_NAME = "EditDescriptorSelector";

	static void ChangeIndex(int delta)
	{
		aspirant::context::editor::PickDescriptor::SetIndex(
			(size_t)common::Utility::PositiveModulo(
				aspirant::context::editor::PickDescriptor::GetIndex() + delta, 
				aspirant::context::editor::PickDescriptor::GetCount()));
	}

	static void OnCommand(const ::Command& command)
	{
		const int ROW_DELTA = 7;
		const int COLUMN_DELTA = 1;
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(::UIState::EDIT_PICK_ROOM);
			break;
		case ::Command::UP:
			ChangeIndex(-ROW_DELTA);
			break;
		case ::Command::DOWN:
			ChangeIndex(+ROW_DELTA);
			break;
		case ::Command::LEFT:
			ChangeIndex(-COLUMN_DELTA);
			break;
		case ::Command::RIGHT:
			ChangeIndex(COLUMN_DELTA);
			break;
		case ::Command::NEXT:
			::Application::SetUIState(::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
		renderer::editor::Room::Draw(renderer);
		renderer::editor::RoomCellObjects::Draw(renderer);
		renderer::editor::PickDescriptor::Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_DESCRIPTOR_SELECTOR, OnCommand);
		::Application::SetRenderHandler(::UIState::EDIT_DESCRIPTOR_SELECTOR, OnDraw);
		::Application::SetUpdateHandler(::UIState::EDIT_DESCRIPTOR_SELECTOR, OnUpdate);
	}
}
