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
		, newRoomColumns(0)
		, newRoomRows(0)
		, roomIndex(0)
	{

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
		GetScenarioSelector().GetScenarioDescriptor()->SetName("");//TODO: magic string
		GetScenarioSelector().GetScenarios().Save();
	}

	void EditorContext::ClearScenarioBrief()
	{
		GetScenarioSelector().GetScenarioDescriptor()->SetBrief("");//TODO: magic string
		GetScenarioSelector().GetScenarios().Save();
	}

	void EditorContext::AppendScenarioName(const std::string& text)
	{
		GetScenarioSelector().GetScenarioDescriptor()->SetName(GetScenarioSelector().GetScenarioDescriptor()->GetName() + text);
		GetScenarioSelector().GetScenarios().Save();
	}

	void EditorContext::AppendScenarioBrief(const std::string& text)
	{
		GetScenarioSelector().GetScenarioDescriptor()->SetBrief(GetScenarioSelector().GetScenarioDescriptor()->GetBrief() + text);
		GetScenarioSelector().GetScenarios().Save();
	}

	void EditorContext::SaveScenario()
	{
		tggd::data::JSONUtility::SaveJSON(GetScenarioSelector().GetScenarioDescriptor()->GetFileName(), GetScenario().ToJSON());
	}
}