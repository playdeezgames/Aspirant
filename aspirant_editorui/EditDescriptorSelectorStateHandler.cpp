#include "EditDescriptorSelectorStateHandler.h"
#include "Utility.h"
#include <sstream>
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditDescriptorSelector";

	bool EditDescriptorSelectorStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		CommonEditorStateHandler::OnDraw(renderer);
		roomRenderer.Draw(renderer);
		roomCellObjectsRenderer.Draw(renderer);
		descriptorSelectorRenderer.Draw(renderer);
		return false;
	}

	void EditDescriptorSelectorStateHandler::ChangeIndex(int delta)
	{
		GetEditorContext().GetDescriptorSelector().SetIndex((size_t)tggd::common::Utility::PositiveModulo((int)GetEditorContext().GetDescriptorSelector().GetIndex() + delta, GetEditorContext().GetDescriptorSelector().GetCount()));
	}


	bool EditDescriptorSelectorStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		const int ROW_DELTA = 7;
		const int COLUMN_DELTA = 1;
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
		case aspirant::commonui::Command::RED:
			SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
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
			SetUIState(aspirant::commonui::UIState::EDIT_NAVIGATE_ROOM);
			break;
		}
		return true;
	}

	bool EditDescriptorSelectorStateHandler::OnUpdate(int)
	{
		return false;
	}

	EditDescriptorSelectorStateHandler::EditDescriptorSelectorStateHandler
	(
		MessageHandler* parent,
		aspirant::editor::context::EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext,
		const aspirant::editor::controls::RoomRenderer& roomRenderer,
		const aspirant::editor::controls::RoomCellObjectsRenderer& roomCellObjectsRenderer,
		const aspirant::editor::controls::DescriptorSelectorRenderer& descriptorSelectorRenderer
	)
		: CommonRoomEditorStateHandler
		(
			parent,
			aspirant::commonui::UIState::EDIT_DESCRIPTOR_SELECTOR,
			LAYOUT_NAME, 
			uiContext,
			editorContext,
			roomRenderer,
			roomCellObjectsRenderer,
			descriptorSelectorRenderer
		)
	{

	}
}