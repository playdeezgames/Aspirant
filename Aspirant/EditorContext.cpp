#include "EditorContext.h"
namespace aspirant
{
	EditorContext::EditorContext(const DescriptorManager& descriptors)
		: scenarioIndex(0)
		, scenario(descriptors)
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