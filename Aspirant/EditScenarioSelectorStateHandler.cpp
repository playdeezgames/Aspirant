#include "EditScenarioSelectorStateHandler.h"
#include <sstream>
#include "Utility.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditScenarioSelector";
	const std::string TEXT_INDEX_STRING_NAME = "EditScenarioSelector.Text.Index";
	const std::string TEXT_ID_STRING_NAME = "EditScenarioSelector.Text.Id";
	const std::string TEXT_NAME_STRING_NAME = "EditScenarioSelector.Text.Name";
	const std::string TEXT_BRIEF_STRING_NAME = "EditScenarioSelector.Text.Brief";

	void EditScenarioSelectorStateHandler::LoadScenario()
	{
		auto scenario = editorContext.GetScenarios().Get(editorContext.GetScenarioIndex());
		editorContext.GetScenario().FromJSON(tggd::common::Utility::LoadJSON(scenario->GetFileName()));
	}


	bool EditScenarioSelectorStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::BACK:
		case Command::RED:
			SetUIState(UIState::START_EDITOR);
			break;
		case Command::NEXT:
		case Command::RIGHT:
			NextScenario();
			break;
		case Command::PREVIOUS:
		case Command::LEFT:
			PreviousScenario();
			break;
		case Command::GREEN:
			LoadScenario();
			SetUIState(UIState::EDIT_SCENARIO);
			break;
		}
		return true;
	}

	void EditScenarioSelectorStateHandler::UpdateIndexText(const ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << "Scenario " << (editorContext.GetScenarioIndex() + 1) << "/" << editorContext.GetScenarios().GetCount();
			stringManager.Set(TEXT_INDEX_STRING_NAME, ss.str());
		}
		else
		{
			stringManager.Set(TEXT_INDEX_STRING_NAME, "No Scenarios");//TODO: magic string
		}
	}

	void EditScenarioSelectorStateHandler::UpdateNameText(const ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			stringManager.Set(TEXT_NAME_STRING_NAME, scenario->GetName());
		}
		else
		{
			stringManager.Set(TEXT_NAME_STRING_NAME, "-");//TODO: magic string
		}
	}

	void EditScenarioSelectorStateHandler::UpdateIdText(const ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << scenario->GetId();
			stringManager.Set(TEXT_ID_STRING_NAME, ss.str());
		}
		else
		{
			stringManager.Set(TEXT_ID_STRING_NAME, "-");//TODO: magic string
		}

	}

	void EditScenarioSelectorStateHandler::UpdateBriefText(const ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			stringManager.Set(TEXT_BRIEF_STRING_NAME, scenario->GetBrief());
		}
		else
		{
			stringManager.Set(TEXT_BRIEF_STRING_NAME, "-");//TODO: magic string
		}
	}

	bool EditScenarioSelectorStateHandler::OnUpdate(int)
	{
		if (editorContext.GetScenarioIndex() >= editorContext.GetScenarios().GetCount())
		{
			editorContext.SetScenarioIndex(0);
		}
		auto scenario = editorContext.GetScenarios().Get(editorContext.GetScenarioIndex());
		UpdateBriefText(scenario);
		UpdateIdText(scenario);
		UpdateIndexText(scenario);
		UpdateNameText(scenario);

		return false;
	}


	EditScenarioSelectorStateHandler::EditScenarioSelectorStateHandler
	(
		MessageHandler* parent,
		tggd::common::LayoutManager& layoutManager,
		EditorContext& editorContext,
		tggd::common::StringManager& stringManager,
		const UIContext& uiContext
	)
		: CommonStateHandler(parent, UIState::EDIT_SCENARIO_SELECTOR, layoutManager.GetDescriptor(LAYOUT_NAME), uiContext)
		, editorContext(editorContext)
		, stringManager(stringManager)
	{

	}

	void EditScenarioSelectorStateHandler::NextScenario()
	{
		if (editorContext.GetScenarios().GetCount() > 0)
		{
			editorContext.SetScenarioIndex((editorContext.GetScenarioIndex() + 1) % editorContext.GetScenarios().GetCount());
		}
	}

	void EditScenarioSelectorStateHandler::PreviousScenario()
	{
		if (editorContext.GetScenarios().GetCount() > 0)
		{
			editorContext.SetScenarioIndex((editorContext.GetScenarioIndex() + editorContext.GetScenarios().GetCount() - 1) % editorContext.GetScenarios().GetCount());
		}
	}
}