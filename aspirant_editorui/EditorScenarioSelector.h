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
		void SetIndex(size_t);
		size_t GetIndex() const;
		const aspirant::game::ScenarioDescriptor* Get() const;
		aspirant::game::ScenarioDescriptor* Get();
		void Next();
		void Previous();
		const aspirant::game::ScenarioDescriptorManager& GetAll() const { return scenarios; }
		aspirant::game::ScenarioDescriptorManager& GetAll() { return scenarios; }
		void ClearName();
		void ClearBrief();
		void AppendName(const std::string&);
		void AppendBrief(const std::string&);
	};
}