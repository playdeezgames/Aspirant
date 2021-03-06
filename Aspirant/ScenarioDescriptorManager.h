#pragma once
#include "ScenarioDescriptor.h"
#include "FinishManager.h"
#include <string>
#include <vector>
namespace aspirant
{
	class ScenarioDescriptorManager: public tggd::common::Finisher
	{
	private:
		std::vector<ScenarioDescriptor*> descriptors;
		std::string fileName;
	public:
		ScenarioDescriptorManager(tggd::common::FinishManager&, const std::string&);
		void Load();
		void Finish();
		void Save() const;
		int GetNextId() const;
		size_t Add(ScenarioDescriptor*);
		size_t GetCount() const;
		const ScenarioDescriptor* Get(size_t) const;
		ScenarioDescriptor* Get(size_t);
	};
}
