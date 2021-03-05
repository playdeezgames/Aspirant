#include "EditorContext.h"
#include "Utility.h"
namespace aspirant
{
	EditorContext::EditorContext
	(
		const DescriptorManager& descriptors,
		ScenarioDescriptorManager& scenarios
	)
		: scenarioIndex(0)
		, scenarios(scenarios)
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

	void EditorContext::UpdateRoomList()
	{
		roomList = scenario.GetRoomKeys();
		if (roomIndex >= roomList.size())
		{
			roomIndex = 0;
		}
	}

	void EditorContext::SetRoomIndex(size_t index)
	{
		roomIndex = index;
	}

	size_t EditorContext::GetRoomIndex() const
	{
		return roomIndex;
	}

	const std::vector<std::string>& EditorContext::GetRoomList() const
	{
		return roomList;
	}

	size_t EditorContext::GetRoomCount() const
	{
		return roomList.size();
	}

	void EditorContext::NextScenario()
	{
		SetScenarioIndex(tggd::common::Utility::NextIndex(GetScenarioIndex(), GetScenarios().GetCount()));
	}

	void EditorContext::PreviousScenario()
	{
		SetScenarioIndex(tggd::common::Utility::PreviousIndex(GetScenarioIndex(), GetScenarios().GetCount()));
	}

	void EditorContext::NextRoom()
	{
		SetRoomIndex(tggd::common::Utility::NextIndex(GetRoomIndex(), GetRoomCount()));
	}

	void EditorContext::PreviousRoom()
	{
		SetRoomIndex(tggd::common::Utility::PreviousIndex(GetRoomIndex(), GetRoomCount()));
	}
}