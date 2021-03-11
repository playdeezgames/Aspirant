#include "EditorContext.h"
#include "Utility.h"
#include "JSONUtility.h"

namespace aspirant
{
	EditorContext::EditorContext
	(
		const aspirant::game::DescriptorManager& descriptors,
		aspirant::game::ScenarioDescriptorManager& scenarios
	)
		: scenarioIndex(0)
		, scenarios(scenarios)
		, scenario(descriptors)
		, newRoomColumns(0)
		, newRoomRows(0)
		, roomIndex(0)
	{

	}

	const aspirant::game::ScenarioDescriptor* EditorContext::GetScenarioDescriptor() const
	{
		return scenarios.Get(GetScenarioIndex());
	}

	aspirant::game::ScenarioDescriptor* EditorContext::GetScenarioDescriptor()
	{
		return scenarios.Get(GetScenarioIndex());
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

	void EditorContext::ResetNewRoom()
	{
		newRoomName = "<replace me>";//TODO: magic string
		newRoomColumns = 10;//TODO: magic number
		newRoomRows = 10;//TODO: magic number
	}

	const std::string& EditorContext::GetNewRoomName() const
	{
		return newRoomName;
	}

	void EditorContext::AppendNewRoomName(const std::string& text)
	{
		newRoomName += text;
	}

	void EditorContext::ClearNewRoomName()
	{
		newRoomName = "";
	}

	size_t EditorContext::GetNewRoomColumns() const
	{
		return newRoomColumns;
	}

	void EditorContext::IncrementNewRoomColumns()
	{
		newRoomColumns++;
	}

	void EditorContext::DecrementNewRoomColumns()
	{
		newRoomColumns = (newRoomColumns <= 1) ? (1) : (newRoomColumns - 1);
	}

	size_t EditorContext::GetNewRoomRows() const
	{
		return newRoomRows;
	}

	void EditorContext::IncrementNewRoomRows()
	{
		newRoomRows++;
	}

	void EditorContext::DecrementNewRoomRows()
	{
		newRoomRows = (newRoomRows <= 1) ? (1) : (newRoomRows - 1);
	}

	void EditorContext::ClearScenarioName()
	{
		GetScenarioDescriptor()->SetName("");//TODO: magic string
		GetScenarios().Save();
	}

	void EditorContext::ClearScenarioBrief()
	{
		GetScenarioDescriptor()->SetBrief("");//TODO: magic string
		GetScenarios().Save();
	}

	void EditorContext::AppendScenarioName(const std::string& text)
	{
		GetScenarioDescriptor()->SetName(GetScenarioDescriptor()->GetName() + text);
		GetScenarios().Save();
	}

	void EditorContext::AppendScenarioBrief(const std::string& text)
	{
		GetScenarioDescriptor()->SetBrief(GetScenarioDescriptor()->GetBrief() + text);
		GetScenarios().Save();
	}

	void EditorContext::SaveScenario()
	{
		tggd::data::JSONUtility::SaveJSON(GetScenarioDescriptor()->GetFileName(), GetScenario().ToJSON());
	}
}