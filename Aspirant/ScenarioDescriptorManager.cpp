#include "ScenarioDescriptorManager.h"
#include "Utility.h"
#include "JSONUtility.h"
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
		auto descriptorList = tggd::data::JSONUtility::LoadJSON(fileName);
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

	void ScenarioDescriptorManager::Save() const
	{
		nlohmann::json descriptorList;
		for (auto& descriptor : descriptors)
		{
			descriptorList.push_back(descriptor->ToJSON());
		}
		tggd::data::JSONUtility::SaveJSON(fileName, descriptorList);
	}

	int ScenarioDescriptorManager::GetNextId() const
	{
		int maximum = 0;
		for (auto& descriptor : descriptors)
		{
			maximum = (descriptor->GetId() > maximum) ? (descriptor->GetId()) : (maximum);
		}
		return maximum + 1;
	}

	size_t ScenarioDescriptorManager::Add(ScenarioDescriptor* descriptor)
	{
		assert(descriptor);
		size_t index = descriptors.size();
		descriptors.push_back(descriptor);
		Save();
		return index;
	}

	size_t ScenarioDescriptorManager::GetCount() const
	{
		return descriptors.size();
	}

	const ScenarioDescriptor* ScenarioDescriptorManager::Get(size_t index) const
	{
		if (index < descriptors.size())
		{
			return descriptors[index];
		}
		else
		{
			return nullptr;
		}
	}

	ScenarioDescriptor* ScenarioDescriptorManager::Get(size_t index)
	{
		if (index < descriptors.size())
		{
			return descriptors[index];
		}
		else
		{
			return nullptr;
		}
	}
}