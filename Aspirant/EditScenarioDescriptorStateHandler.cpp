#include "EditScenarioDescriptorStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditScenarioDescriptor";
	const std::string COLOR_NAME_SCENARIO_NAME = "EditScenarioDescriptor.Color.ScenarioName";
	const std::string COLOR_NAME_BRIEF = "EditScenarioDescriptor.Color.Brief";
	const std::string COLOR_NAME_BACK = "EditScenarioDescriptor.Color.Back";
	const std::string TEXT_NAME_SCENARIO_NAME ="EditScenarioDescriptor.Text.ScenarioName";
	const std::string TEXT_NAME_BRIEF ="EditScenarioDescriptor.Text.Brief";

	bool EditScenarioDescriptorStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
			switch (GetMenuItem())
			{
			case EditScenarioDescriptorItem::SCENARIO_NAME:
				GetEditorContext().ClearScenarioName();
				return true;
			case EditScenarioDescriptorItem::BRIEF:
				GetEditorContext().ClearScenarioBrief();
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
		GetUIContext().GetStringManager().Set(TEXT_NAME_SCENARIO_NAME, GetEditorContext().GetScenarioDescriptor()->GetName());
		GetUIContext().GetStringManager().Set(TEXT_NAME_BRIEF, GetEditorContext().GetScenarioDescriptor()->GetBrief());
		return MenuStateHandler<EditScenarioDescriptorItem>::OnUpdate();
	}

	bool EditScenarioDescriptorStateHandler::OnText(const std::string& text)
	{
		switch (GetMenuItem())
		{
		case EditScenarioDescriptorItem::SCENARIO_NAME:
			GetEditorContext().AppendScenarioName(text);
			break;
		case EditScenarioDescriptorItem::BRIEF:
			GetEditorContext().AppendScenarioBrief(text);
			break;
		}
		return true;
	}

	void EditScenarioDescriptorStateHandler::ActivateItem(const EditScenarioDescriptorItem& menuItem)
	{
		switch (menuItem)
		{
		case EditScenarioDescriptorItem::BACK:
			SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		}
	}

	EditScenarioDescriptorStateHandler::EditScenarioDescriptorStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext
	)
		: EditorMenuStateHandler(parent, aspirant::commonui::UIState::EDIT_SCENARIO_DESCRIPTOR, aspirant::commonui::UIState::EDIT_SCENARIO, LAYOUT_NAME, EditScenarioDescriptorItem::BACK, uiContext, editorContext)
	{
		AddMenuItem(EditScenarioDescriptorItem::SCENARIO_NAME, aspirant::commonui::MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_SCENARIO_NAME, EditScenarioDescriptorItem::BACK, EditScenarioDescriptorItem::BRIEF));
		AddMenuItem(EditScenarioDescriptorItem::BRIEF, aspirant::commonui::MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME, EditScenarioDescriptorItem::BACK));
		AddMenuItem(EditScenarioDescriptorItem::BACK, aspirant::commonui::MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_BACK, EditScenarioDescriptorItem::BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME));
	}

}