#include "EditScenarioDescriptorStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditScenarioDescriptor";
	const std::string COLOR_NAME_SCENARIO_NAME = "EditScenarioDescriptor.Color.ScenarioName";
	const std::string COLOR_NAME_BRIEF = "EditScenarioDescriptor.Color.Brief";
	const std::string COLOR_NAME_BACK = "EditScenarioDescriptor.Color.Back";
	const std::string TEXT_NAME_SCENARIO_NAME ="EditScenarioDescriptor.Text.ScenarioName";
	const std::string TEXT_NAME_BRIEF ="EditScenarioDescriptor.Text.Brief";

	bool EditScenarioDescriptorStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::BACK:
			switch (GetMenuItem())
			{
			case EditScenarioDescriptorItem::SCENARIO_NAME:
				editorContext.ClearScenarioName();
				return true;
			case EditScenarioDescriptorItem::BRIEF:
				editorContext.ClearScenarioBrief();
				return true;
			default:
				return MenuStateHandler<EditScenarioDescriptorItem>::OnCommand(command);
			}
		default:
			return MenuStateHandler<EditScenarioDescriptorItem>::OnCommand(command);
		}
	}

	bool EditScenarioDescriptorStateHandler::OnUpdate()
	{
		GetUIContext().GetStringManager().Set(TEXT_NAME_SCENARIO_NAME, editorContext.GetScenarioDescriptor()->GetName());
		GetUIContext().GetStringManager().Set(TEXT_NAME_BRIEF, editorContext.GetScenarioDescriptor()->GetBrief());
		return MenuStateHandler<EditScenarioDescriptorItem>::OnUpdate();
	}

	bool EditScenarioDescriptorStateHandler::OnText(const std::string& text)
	{
		switch (GetMenuItem())
		{
		case EditScenarioDescriptorItem::SCENARIO_NAME:
			editorContext.AppendScenarioName(text);
			break;
		case EditScenarioDescriptorItem::BRIEF:
			editorContext.AppendScenarioBrief(text);
			break;
		}
		return true;
	}

	void EditScenarioDescriptorStateHandler::ActivateItem(const EditScenarioDescriptorItem& menuItem)
	{
		switch (menuItem)
		{
		case EditScenarioDescriptorItem::BACK:
			SetUIState(UIState::EDIT_SCENARIO);
			break;
		}
	}

	EditScenarioDescriptorStateHandler::EditScenarioDescriptorStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const UIContext& uiContext
	)
		:MenuStateHandler(parent, UIState::EDIT_SCENARIO_DESCRIPTOR, UIState::EDIT_SCENARIO, LAYOUT_NAME, EditScenarioDescriptorItem::BACK, uiContext)
		, editorContext(editorContext)
	{
		AddMenuItem(EditScenarioDescriptorItem::SCENARIO_NAME, MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_SCENARIO_NAME, EditScenarioDescriptorItem::BACK, EditScenarioDescriptorItem::BRIEF));
		AddMenuItem(EditScenarioDescriptorItem::BRIEF, MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME, EditScenarioDescriptorItem::BACK));
		AddMenuItem(EditScenarioDescriptorItem::BACK, MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_BACK, EditScenarioDescriptorItem::BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME));
	}

}