#include "EditScenarioSelectorStateHandler.h"
#include <sstream>
#include "Utility.h"
namespace aspirant::editorui
{
	const std::string LAYOUT_NAME = "EditScenarioSelector";
	const std::string TEXT_INDEX_STRING_NAME = "EditScenarioSelector.Text.Index";
	const std::string TEXT_ID_STRING_NAME = "EditScenarioSelector.Text.Id";
	const std::string TEXT_NAME_STRING_NAME = "EditScenarioSelector.Text.Name";
	const std::string TEXT_BRIEF_STRING_NAME = "EditScenarioSelector.Text.Brief";

	void EditScenarioSelectorStateHandler::LoadScenario()
	{
		auto scenario = GetEditorContext().GetScenarios().Get(GetEditorContext().GetScenarioIndex());
		GetEditorContext().GetScenario().FromJSON(tggd::data::JSONUtility::LoadJSON(scenario->GetFileName()));
	}


	bool EditScenarioSelectorStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
		case aspirant::commonui::Command::RED:
			SetUIState(aspirant::commonui::UIState::START_EDITOR);
			break;
		case aspirant::commonui::Command::NEXT:
		case aspirant::commonui::Command::RIGHT:
			GetEditorContext().NextScenario();
			break;
		case aspirant::commonui::Command::PREVIOUS:
		case aspirant::commonui::Command::LEFT:
			GetEditorContext().PreviousScenario();
			break;
		case aspirant::commonui::Command::GREEN:
			LoadScenario();
			SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		}
		return true;
	}

	void EditScenarioSelectorStateHandler::UpdateIndexText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << "Scenario " << (GetEditorContext().GetScenarioIndex() + 1) << "/" << GetEditorContext().GetScenarios().GetCount();
			GetUIContext().GetStringManager().Set(TEXT_INDEX_STRING_NAME, ss.str());
		}
		else
		{
			GetUIContext().GetStringManager().Set(TEXT_INDEX_STRING_NAME, "No Scenarios");//TODO: magic string
		}
	}

	void EditScenarioSelectorStateHandler::UpdateNameText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			GetUIContext().GetStringManager().Set(TEXT_NAME_STRING_NAME, scenario->GetName());
		}
		else
		{
			GetUIContext().GetStringManager().Set(TEXT_NAME_STRING_NAME, "-");//TODO: magic string
		}
	}

	void EditScenarioSelectorStateHandler::UpdateIdText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << scenario->GetId();
			GetUIContext().GetStringManager().Set(TEXT_ID_STRING_NAME, ss.str());
		}
		else
		{
			GetUIContext().GetStringManager().Set(TEXT_ID_STRING_NAME, "-");//TODO: magic string
		}

	}

	void EditScenarioSelectorStateHandler::UpdateBriefText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			GetUIContext().GetStringManager().Set(TEXT_BRIEF_STRING_NAME, scenario->GetBrief());
		}
		else
		{
			GetUIContext().GetStringManager().Set(TEXT_BRIEF_STRING_NAME, "-");//TODO: magic string
		}
	}

	bool EditScenarioSelectorStateHandler::OnUpdate(int)
	{
		if (GetEditorContext().GetScenarioIndex() >= GetEditorContext().GetScenarios().GetCount())
		{
			GetEditorContext().SetScenarioIndex(0);
		}
		auto scenario = GetEditorContext().GetScenarios().Get(GetEditorContext().GetScenarioIndex());
		UpdateBriefText(scenario);
		UpdateIdText(scenario);
		UpdateIndexText(scenario);
		UpdateNameText(scenario);

		return false;
	}


	EditScenarioSelectorStateHandler::EditScenarioSelectorStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext
	)
		: CommonEditorStateHandler(parent, aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR, LAYOUT_NAME, uiContext, editorContext)
	{

	}

}