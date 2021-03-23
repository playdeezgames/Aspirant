#include "Aspirant.State.Editor.PickDescriptor.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "RoomRenderer.h"
#include "RoomCellObjectsRenderer.h"
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

	static void OnCommand(const aspirant::Command& command)
	{
		const int ROW_DELTA = 7;
		const int COLUMN_DELTA = 1;
		switch (command)
		{
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
			break;
		case aspirant::Command::UP:
			ChangeIndex(-ROW_DELTA);
			break;
		case aspirant::Command::DOWN:
			ChangeIndex(+ROW_DELTA);
			break;
		case aspirant::Command::LEFT:
			ChangeIndex(-COLUMN_DELTA);
			break;
		case aspirant::Command::RIGHT:
			ChangeIndex(COLUMN_DELTA);
			break;
		case aspirant::Command::NEXT:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
		aspirant::editor::controls::RoomRenderer::Draw(renderer);
		aspirant::editor::controls::RoomCellObjectsRenderer::Draw(renderer);
		renderer::editor::PickDescriptor::Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::EDIT_DESCRIPTOR_SELECTOR, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::EDIT_DESCRIPTOR_SELECTOR, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::EDIT_DESCRIPTOR_SELECTOR, OnUpdate);
	}
}
