#include "EditorScenarioSelector.h"
#include "Utility.h"
#include "JSONUtility.h"

namespace aspirant::editorui
{
	const aspirant::game::ScenarioDescriptor* EditorScenarioSelector::Get() const
	{
		return scenarios.Get(GetIndex());
	}

	aspirant::game::ScenarioDescriptor* EditorScenarioSelector::Get()
	{
		return scenarios.Get(GetIndex());
	}


	void EditorScenarioSelector::SetIndex(size_t index)
	{
		scenarioIndex = index;
	}

	size_t EditorScenarioSelector::GetIndex() const
	{
		return scenarioIndex;
	}

	void EditorScenarioSelector::Next()
	{
		SetIndex(tggd::common::Utility::NextIndex(GetIndex(), GetAll().GetCount()));
	}

	void EditorScenarioSelector::Previous()
	{
		SetIndex(tggd::common::Utility::PreviousIndex(GetIndex(), GetAll().GetCount()));
	}

	void EditorScenarioSelector::ClearName()
	{
		Get()->SetName("");//TODO: magic string
		GetAll().Save();
	}

	void EditorScenarioSelector::ClearBrief()
	{
		Get()->SetBrief("");//TODO: magic string
		GetAll().Save();
	}

	void EditorScenarioSelector::AppendName(const std::string& text)
	{
		Get()->SetName(Get()->GetName() + text);
		GetAll().Save();
	}

	void EditorScenarioSelector::AppendBrief(const std::string& text)
	{
		Get()->SetBrief(Get()->GetBrief() + text);
		GetAll().Save();
	}


}