#include "DescriptorManager.h"
#include "FinishManager.h"
#include <map>
#include "FinishUtility.h"
#include "JSONUtility.h"
#include "TerrainDescriptor.h"
#include "CreatureDescriptor.h"
namespace aspirant::game::DescriptorManager
{
	const std::string PROPERTY_TYPE = "type";
	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";
	static std::map<std::string, aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>*> descriptors;
	static std::vector<std::string> identifiers;

	static std::string ParseKey(const nlohmann::json& key)
	{
		return key;
	}

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	aspirant::game::BaseDescriptor<ScenarioObjectInstance>* ParseDescriptor(const std::string& name, const nlohmann::json& properties)
	{
		const auto& descriptorType = properties[PROPERTY_TYPE];
		if (descriptorType == TYPE_TERRAIN)
		{
			return new TerrainDescriptor(name, properties);
		}
		else if (descriptorType == TYPE_CREATURE)
		{
			return new CreatureDescriptor(name, properties);
		}
		else
		{
			throw "INVALID DESCRIPTOR TYPE";
		}
	}

	static void Finish()
	{
		tggd::common::FinishUtility::SafeDeleteMap(descriptors);
	}

	void Start(const std::string& filename)
	{
		tggd::common::FinishManager::Add(Finish);
		nlohmann::json properties = tggd::data::JSONUtility::LoadJSON(filename);
		for (auto& item : properties.items())
		{
			auto identifier = ParseKey(item.key());
			identifiers.push_back(identifier);
			descriptors[identifier] =
				ParseDescriptor(identifier, item.value());
		}
	}

	const aspirant::game::BaseDescriptor<ScenarioObjectInstance>* Get(std::string& key)
	{
		return descriptors[key];
	}


}