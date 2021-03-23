#include "Game.ScenarioDescriptors.h"
#include "Common.Utility.h"
#include "Data.JSON.h"
#include "FinishUtility.h"
namespace game::ScenarioDescriptors
{
	static std::vector<::game::ScenarioDescriptor*> descriptors;
	static std::string fileName;

	static void Finish()
	{
		for (auto& descriptor : descriptors)
		{
			tggd::common::FinishUtility::SafeDelete(descriptor);
		}
		descriptors.clear();
	}

	void Load(const std::string& filename)
	{
		common::Finishers::Add(Finish);
		fileName = filename;
		auto descriptorList = data::JSON::Load(fileName);
		for (auto& properties : descriptorList)
		{
			descriptors.push_back(new ::game::ScenarioDescriptor(properties));
		}
	}

	void Save()
	{
		nlohmann::json descriptorList;
		for (auto& descriptor : descriptors)
		{
			descriptorList.push_back(descriptor->ToJSON());
		}
		data::JSON::Save(fileName, descriptorList);
	}

	int GetNextId()
	{
		int maximum = 0;
		for (auto& descriptor : descriptors)
		{
			maximum = (descriptor->GetId() > maximum) ? (descriptor->GetId()) : (maximum);
		}
		return maximum + 1;
	}

	size_t Add(::game::ScenarioDescriptor* descriptor)
	{
		size_t index = descriptors.size();
		descriptors.push_back(descriptor);
		Save();
		return index;
	}

	size_t GetCount()
	{
		return descriptors.size();
	}

	::game::ScenarioDescriptor* Get(size_t index)
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