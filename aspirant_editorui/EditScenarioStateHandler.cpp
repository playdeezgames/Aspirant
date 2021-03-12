#include "EditScenarioStateHandler.h"
#include <sstream>
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditScenario";
	const std::string ITEM_DESCRIPTOR_COLOR_NAME = "EditScenario.Color.Descriptor";
	const std::string ITEM_OPEN_ROOM_COLOR_NAME = "EditScenario.Color.OpenRoom";
	const std::string ITEM_NEW_ROOM_COLOR_NAME = "EditScenario.Color.NewRoom";
	const std::string ITEM_BACK_COLOR_NAME = "EditScenario.Color.Back";
	const std::string HEADER_TEXT_NAME = "EditScenario.Text.Header";

	void EditScenarioStateHandler::UpdateHeader()
	{
		std::stringstream ss;
		auto scenario = GetEditorContext().GetScenarioSelector().GetScenarios().Get(GetEditorContext().GetScenarioSelector().GetScenarioIndex());
		ss << scenario->GetName() << "(id=" << scenario->GetId() << ")";//TODO: magic strings
		GetStringManager().Set(HEADER_TEXT_NAME, ss.str());
	}

	bool EditScenarioStateHandler::OnUpdate()
	{
		UpdateHeader();

		return MenuStateHandler::OnUpdate();
	}


	void EditScenarioStateHandler::ActivateItem(const EditScenarioItem& menuItem)
	{
		switch (menuItem)
		{
		case EditScenarioItem::BACK:
			SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		case EditScenarioItem::DESCRIPTOR:
			SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO_DESCRIPTOR);
			break;
		case EditScenarioItem::OPEN_ROOM:
			GetEditorContext().UpdateRoomList();
			SetUIState(aspirant::commonui::UIState::EDIT_PICK_ROOM);
			break;
		case EditScenarioItem::NEW_ROOM:
			GetEditorContext().ResetNewRoom();
			SetUIState(aspirant::commonui::UIState::EDIT_NEW_ROOM);
			break;
		}
	}

	EditScenarioStateHandler::EditScenarioStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext
	)
		: EditorMenuStateHandler
		(
			parent, 
			aspirant::commonui::UIState::EDIT_SCENARIO,
			aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR,
			LAYOUT_NAME, 
			EditScenarioItem::BACK,
			uiContext,
			editorContext
		)
	{
		AddMenuItem(EditScenarioItem::DESCRIPTOR, aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_DESCRIPTOR_COLOR_NAME, EditScenarioItem::BACK, EditScenarioItem::OPEN_ROOM));
		AddMenuItem(EditScenarioItem::OPEN_ROOM, aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_OPEN_ROOM_COLOR_NAME, EditScenarioItem::DESCRIPTOR, EditScenarioItem::NEW_ROOM));
		AddMenuItem(EditScenarioItem::NEW_ROOM, aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_NEW_ROOM_COLOR_NAME, EditScenarioItem::OPEN_ROOM, EditScenarioItem::BACK));
		AddMenuItem(EditScenarioItem::BACK, aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_BACK_COLOR_NAME, EditScenarioItem::NEW_ROOM, EditScenarioItem::DESCRIPTOR));
	}

}