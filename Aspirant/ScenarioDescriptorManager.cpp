#include "ScenarioDescriptorManager.h"
#include "Utility.h"
namespace aspirant
{
	ScenarioDescriptorManager::ScenarioDescriptorManager(tggd::common::FinishManager& finishManager)
		: descriptors()
	{
		finishManager.Add(this);
	}

	void ScenarioDescriptorManager::Start(const std::string& fileName)
	{
		auto descriptorList = tggd::common::Utility::LoadJSON(fileName);
		for (auto& properties : descriptorList)
		{
			descriptors.push_back(new ScenarioDescriptor(properties));
		}
	}

	void ScenarioDescriptorManager::Finish()
	{
		for (auto& descriptor : descriptors)
		{
			tggd::common::Utility::SafeDelete(descriptor);
		}
	}
}