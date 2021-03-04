#include "EditScenarioStateHandler.h"
#include <sstream>
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditScenario";
	const std::string ITEM_DESCRIPTOR_COLOR_NAME = "EditScenario.Color.Descriptor";
	const std::string ITEM_ROOMS_COLOR_NAME = "EditScenario.Color.Rooms";
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
		case EditScenarioItem::ROOMS:
			SetUIState(UIState::EDIT_PICK_ROOM);
			break;
		}
	}

	EditScenarioStateHandler::EditScenarioStateHandler
	(
		MessageHandler* parent,
		const UIState& uiState,
		tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager,
		const EditorContext& editorContext
	)
		: MenuStateHandler
		(
			parent, 
			uiState, 
			UIState::EDIT_SCENARIO, 
			UIState::EDIT_SCENARIO_SELECTOR, 
			layoutManager.GetDescriptor(LAYOUT_NAME), 
			stringManager, 
			EditScenarioItem::BACK
		)
		, editorContext(editorContext)
	{
		AddMenuItem(EditScenarioItem::DESCRIPTOR, MenuItemDescriptor<EditScenarioItem>(ITEM_DESCRIPTOR_COLOR_NAME, EditScenarioItem::BACK, EditScenarioItem::ROOMS));
		AddMenuItem(EditScenarioItem::ROOMS, MenuItemDescriptor<EditScenarioItem>(ITEM_ROOMS_COLOR_NAME, EditScenarioItem::DESCRIPTOR, EditScenarioItem::BACK));
		AddMenuItem(EditScenarioItem::BACK, MenuItemDescriptor<EditScenarioItem>(ITEM_BACK_COLOR_NAME, EditScenarioItem::ROOMS, EditScenarioItem::DESCRIPTOR));
	}

}