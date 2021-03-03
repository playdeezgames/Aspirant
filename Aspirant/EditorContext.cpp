#include "EditorContext.h"
namespace aspirant
{
	EditorContext::EditorContext()
		: scenarioIndex(0)
		, scenario()
	{

	}

	void EditorContext::SetScenarioIndex(size_t index)
	{
		scenarioIndex = index;
	}

	size_t EditorContext::GetScenarioIndex() const
	{
		return scenarioIndex;
	}
}