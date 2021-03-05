#pragma once
#include "Scenario.h"
#include "DescriptorManager.h"
#include "ScenarioDescriptorManager.h"
#include <vector>
namespace aspirant
{
	class EditorContext
	{
	private:
		ScenarioDescriptorManager& scenarios;
		size_t scenarioIndex;

		Scenario scenario;

		std::vector<std::string> roomList;
		size_t roomIndex;
	public:
		EditorContext(const DescriptorManager&, ScenarioDescriptorManager&);
		void SetScenarioIndex(size_t);
		size_t GetScenarioIndex() const;
		void NextScenario();
		void PreviousScenario();
		const Scenario& GetScenario() const { return scenario; }
		Scenario& GetScenario() { return scenario; }
		const ScenarioDescriptorManager& GetScenarios() const { return scenarios; }
		ScenarioDescriptorManager& GetScenarios() { return scenarios; }
		void UpdateRoomList();
		void SetRoomIndex(size_t);
		size_t GetRoomIndex() const;
		const std::vector<std::string>& GetRoomList() const;
		size_t GetRoomCount() const;
		void NextRoom();
		void PreviousRoom();
	};
}
