#pragma once
#include "Scenario.h"
#include "DescriptorManager.h"
#include "ScenarioDescriptorManager.h"
namespace aspirant
{
	class EditorContext
	{
	private:
		ScenarioDescriptorManager& scenarios;
		size_t scenarioIndex;
		Scenario scenario;
	public:
		EditorContext(const DescriptorManager&, ScenarioDescriptorManager&);
		void SetScenarioIndex(size_t);
		size_t GetScenarioIndex() const;
		const Scenario& GetScenario() const { return scenario; }
		Scenario& GetScenario() { return scenario; }
		const ScenarioDescriptorManager& GetScenarios() const { return scenarios; }
		ScenarioDescriptorManager& GetScenarios() { return scenarios; }
	};
}
