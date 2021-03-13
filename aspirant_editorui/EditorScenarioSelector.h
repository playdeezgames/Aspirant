#pragma once
#include "ScenarioDescriptorManager.h"
namespace aspirant::editorui
{
	class EditorScenarioSelector
	{
	private:
		aspirant::game::ScenarioDescriptorManager& scenarios;
		size_t scenarioIndex;
	public:
		EditorScenarioSelector(aspirant::game::ScenarioDescriptorManager& scenarios)
			: scenarios(scenarios)
			, scenarioIndex(0)
		{

		}
		void SetScenarioIndex(size_t);
		size_t GetScenarioIndex() const;
		const aspirant::game::ScenarioDescriptor* GetScenarioDescriptor() const;
		aspirant::game::ScenarioDescriptor* GetScenarioDescriptor();
		void NextScenario();
		void PreviousScenario();
		const aspirant::game::ScenarioDescriptorManager& GetScenarios() const { return scenarios; }
		aspirant::game::ScenarioDescriptorManager& GetScenarios() { return scenarios; }
		void ClearScenarioName();
		void ClearScenarioBrief();
		void AppendScenarioName(const std::string&);
		void AppendScenarioBrief(const std::string&);
	};
}