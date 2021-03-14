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
	{

	}

	void EditorContext::SaveScenario()
	{
		tggd::data::JSONUtility::SaveJSON(GetScenarioSelector().Get()->GetFileName(), GetScenario().ToJSON());
	}

	const aspirant::game::ScenarioRoom* EditorContext::GetRoom() const
	{
		if (GetRoomList().GetRoomCount() > GetRoomList().GetRoomIndex())
		{
			return scenario.GetRoom(GetRoomList().GetRoomList()[GetRoomList().GetRoomIndex()]);
		}
		else
		{
			return nullptr;
		}
	}

	aspirant::game::ScenarioRoom* EditorContext::GetRoom()
	{
		if (GetRoomList().GetRoomCount() > GetRoomList().GetRoomIndex())
		{
			return scenario.GetRoom(GetRoomList().GetRoomList()[GetRoomList().GetRoomIndex()]);
		}
		else
		{
			return nullptr;
		}
	}

}