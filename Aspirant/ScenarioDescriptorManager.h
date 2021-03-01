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
	public:
		ScenarioDescriptorManager(tggd::common::FinishManager&);
		void Start(const std::string&);
		void Finish();
	};
}
