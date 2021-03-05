#include "EditScenarioStateHandler.h"
#include <sstream>
namespace aspirant
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
		auto scenario = editorContext.GetScenarios().Get(editorContext.GetScenarioIndex());
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
			SetUIState(UIState::EDIT_SCENARIO_SELECTOR);
			break;
		case EditScenarioItem::DESCRIPTOR:
			SetUIState(UIState::EDIT_SCENARIO_DESCRIPTOR);
			break;
		case EditScenarioItem::OPEN_ROOM:
			editorContext.UpdateRoomList();
			SetUIState(UIState::EDIT_PICK_ROOM);
			break;
		case EditScenarioItem::NEW_ROOM:
			editorContext.ResetNewRoom();
			SetUIState(UIState::EDIT_NEW_ROOM);
			break;
		}
	}

	EditScenarioStateHandler::EditScenarioStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const UIContext& uiContext
	)
		: MenuStateHandler
		(
			parent, 
			UIState::EDIT_SCENARIO, 
			UIState::EDIT_SCENARIO_SELECTOR, 
			LAYOUT_NAME, 
			EditScenarioItem::BACK,
			uiContext
		)
		, editorContext(editorContext)
	{
		AddMenuItem(EditScenarioItem::DESCRIPTOR, MenuItemDescriptor<EditScenarioItem>(ITEM_DESCRIPTOR_COLOR_NAME, EditScenarioItem::BACK, EditScenarioItem::OPEN_ROOM));
		AddMenuItem(EditScenarioItem::OPEN_ROOM, MenuItemDescriptor<EditScenarioItem>(ITEM_OPEN_ROOM_COLOR_NAME, EditScenarioItem::DESCRIPTOR, EditScenarioItem::NEW_ROOM));
		AddMenuItem(EditScenarioItem::NEW_ROOM, MenuItemDescriptor<EditScenarioItem>(ITEM_NEW_ROOM_COLOR_NAME, EditScenarioItem::OPEN_ROOM, EditScenarioItem::BACK));
		AddMenuItem(EditScenarioItem::BACK, MenuItemDescriptor<EditScenarioItem>(ITEM_BACK_COLOR_NAME, EditScenarioItem::NEW_ROOM, EditScenarioItem::DESCRIPTOR));
	}

}