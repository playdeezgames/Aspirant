#pragma once
#include "Scenario.h"
#include "DescriptorManager.h"
#include "ScenarioDescriptorManager.h"
#include <vector>
#include "EditorScenarioSelector.h"
namespace aspirant::editorui
{
	class EditorContext
	{
	private:
		EditorScenarioSelector scenarioSelector;
		aspirant::game::Scenario scenario;

		std::vector<std::string> roomList;
		size_t roomIndex;

		std::string newRoomName;
		size_t newRoomColumns;
		size_t newRoomRows;
	public:
		EditorContext(const aspirant::game::DescriptorManager&, aspirant::game::ScenarioDescriptorManager&);

		const EditorScenarioSelector& GetScenarioSelector() const
		{
			return scenarioSelector;
		}
		EditorScenarioSelector& GetScenarioSelector()
		{
			return scenarioSelector;
		}


		const aspirant::game::Scenario& GetScenario() const { return scenario; }
		aspirant::game::Scenario& GetScenario() { return scenario; }
		void ClearScenarioName();
		void ClearScenarioBrief();
		void AppendScenarioName(const std::string&);
		void AppendScenarioBrief(const std::string&);
		void SaveScenario();

		void UpdateRoomList();
		void SetRoomIndex(size_t);
		size_t GetRoomIndex() const;
		const std::vector<std::string>& GetRoomList() const;
		size_t GetRoomCount() const;
		void NextRoom();
		void PreviousRoom();
		void ResetNewRoom();

		const std::string& GetNewRoomName() const;
		void AppendNewRoomName(const std::string&);
		void ClearNewRoomName();
		size_t GetNewRoomColumns() const;
		void IncrementNewRoomColumns();
		void DecrementNewRoomColumns();
		size_t GetNewRoomRows() const;
		void IncrementNewRoomRows();
		void DecrementNewRoomRows();

	};
}
