#include "EditorContext.h"
#include "Utility.h"
#include "JSONUtility.h"

namespace aspirant::editor::context
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
		, roomView(tggd::graphics::XY<size_t>(10,10))//TODO: magic number!
		, roomCellObjects(roomView, roomList)
		, descriptorSelector(descriptors)
	{

	}

	void EditorContext::SaveScenario()
	{
		tggd::data::JSONUtility::SaveJSON(GetScenarioSelector().Get()->GetFileName(), GetScenario().ToJSON());
	}
}