#include "EditorScenarioSelector.h"
namespace aspirant::editor::context::EditorScenarioSelector
{
	static int scenarioIndex = 0;
	void SetIndex(int index)
	{
		scenarioIndex = index;
	}
}