#pragma once
#include "Scenario.h"
#include "DescriptorManager.h"
namespace aspirant
{
	class EditorContext
	{
	private:
		size_t scenarioIndex;
		Scenario scenario;
	public:
		EditorContext(const DescriptorManager&);
		void SetScenarioIndex(size_t);
		size_t GetScenarioIndex() const;
		const Scenario& GetScenario() const { return scenario; }
		Scenario& GetScenario() { return scenario; }
	};
}
