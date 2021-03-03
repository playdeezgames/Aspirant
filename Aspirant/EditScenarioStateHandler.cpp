#include "EditScenarioStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditScenario";
	const std::string ITEM_DESCRIPTOR_COLOR_NAME = "EditScenario.Color.Descriptor";
	const std::string ITEM_ROOMS_COLOR_NAME = "EditScenario.Color.Rooms";
	const std::string ITEM_BACK_COLOR_NAME = "EditScenario.Color.Back";

	void EditScenarioStateHandler::ActivateItem(const EditScenarioItem&)
	{

	}

	EditScenarioStateHandler::EditScenarioStateHandler
	(
		MessageHandler* parent,
		const UIState& uiState,
		tggd::common::LayoutManager& layoutManager,
		tggd::common::StringManager& stringManager,
		const ScenarioDescriptorManager& scenarios,
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
		, scenarios(scenarios)
		, editorContext(editorContext)
	{
		AddMenuItem(EditScenarioItem::DESCRIPTOR, MenuItemDescriptor<EditScenarioItem>(ITEM_DESCRIPTOR_COLOR_NAME, EditScenarioItem::BACK, EditScenarioItem::ROOMS));
		AddMenuItem(EditScenarioItem::ROOMS, MenuItemDescriptor<EditScenarioItem>(ITEM_ROOMS_COLOR_NAME, EditScenarioItem::DESCRIPTOR, EditScenarioItem::BACK));
		AddMenuItem(EditScenarioItem::BACK, MenuItemDescriptor<EditScenarioItem>(ITEM_BACK_COLOR_NAME, EditScenarioItem::ROOMS, EditScenarioItem::DESCRIPTOR));
	}

}