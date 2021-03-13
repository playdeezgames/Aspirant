#include "EditorContext.h"
#include "Utility.h"
#include "JSONUtility.h"

namespace aspirant::editorui
{
	EditorContext::EditorContext
	(
		const aspirant::game::DescriptorManager& descriptors,
		aspirant::game::ScenarioDescriptorManager& scenarios
	)
		: scenarioSelector(scenarios)
		, scenario(descriptors)
		, newRoom()
		, roomList(scenario)
	{

	}

	void EditorContext::SaveScenario()
	{
		tggd::data::JSONUtility::SaveJSON(GetScenarioSelector().GetScenarioDescriptor()->GetFileName(), GetScenario().ToJSON());
	}
}