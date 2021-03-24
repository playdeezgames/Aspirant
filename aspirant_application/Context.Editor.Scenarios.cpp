#include "Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
#include "Common.Utility.h"
namespace context::editor::Scenarios
{
	static size_t scenarioIndex = 0;
	static void DoBusinessRules()
	{
		if (scenarioIndex >= ::game::ScenarioDescriptors::GetCount())
		{
			scenarioIndex = 0;
		}
	}

	void SetIndex(size_t index)
	{
		scenarioIndex = index;
	}

	size_t GetIndex()
	{
		DoBusinessRules();
		return scenarioIndex;
	}

	void Next()
	{
		SetIndex(common::Utility::NextIndex(GetIndex(), ::game::ScenarioDescriptors::GetCount()));
	}

	void Previous()
	{
		SetIndex(common::Utility::PreviousIndex(GetIndex(), ::game::ScenarioDescriptors::GetCount()));
	}
}