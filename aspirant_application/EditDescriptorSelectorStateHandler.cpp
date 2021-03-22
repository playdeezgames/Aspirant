#include "EditDescriptorSelectorStateHandler.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "RoomRenderer.h"
#include "RoomCellObjectsRenderer.h"
#include "DescriptorSelectorRenderer.h"
#include "Utility.h"
#include "EditorDescriptorSelectorContext.h"
namespace aspirant::editorui::EditDescriptorSelectorStateHandler
{
	const std::string LAYOUT_NAME = "EditDescriptorSelector";

	static void ChangeIndex(int delta)
	{
		aspirant::editor::context::EditorDescriptorSelectorContext::SetIndex(
			(size_t)tggd::common::Utility::PositiveModulo(
				aspirant::editor::context::EditorDescriptorSelectorContext::GetIndex() + delta, 
				aspirant::editor::context::EditorDescriptorSelectorContext::GetCount()));
	}

	static void OnCommand(const aspirant::commonui::Command& command)
	{
		const int ROW_DELTA = 7;
		const int COLUMN_DELTA = 1;
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
			break;
		case aspirant::commonui::Command::UP:
			ChangeIndex(-ROW_DELTA);
			break;
		case aspirant::commonui::Command::DOWN:
			ChangeIndex(+ROW_DELTA);
			break;
		case aspirant::commonui::Command::LEFT:
			ChangeIndex(-COLUMN_DELTA);
			break;
		case aspirant::commonui::Command::RIGHT:
			ChangeIndex(COLUMN_DELTA);
			break;
		case aspirant::commonui::Command::NEXT:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
		aspirant::editor::controls::RoomRenderer::Draw(renderer);
		aspirant::editor::controls::RoomCellObjectsRenderer::Draw(renderer);
		aspirant::editor::controls::DescriptorSelectorRenderer::Draw(renderer);
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
