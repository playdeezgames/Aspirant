#include "ScenarioDescriptorManager.h"
#include "Utility.h"
namespace aspirant
{
	ScenarioDescriptorManager::ScenarioDescriptorManager
	(
		tggd::common::FinishManager& finishManager, 
		const std::string& fileName
	)
		: descriptors()
		, fileName(fileName)
	{
		finishManager.Add(this);
	}

	void ScenarioDescriptorManager::Load()
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

	void ScenarioDescriptorManager::Save()
	{
		nlohmann::json descriptorList;
		for (auto& descriptor : descriptors)
		{
			descriptorList.push_back(descriptor->ToJSON());
		}
		tggd::common::Utility::SaveJSON(fileName, descriptorList);
	}
}