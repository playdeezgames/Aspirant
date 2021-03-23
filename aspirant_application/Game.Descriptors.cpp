#include "Game.Descriptors.h"
#include "Common.Finishers.h"
#include <map>
#include "FinishUtility.h"
#include "Data.JSON.h"
#include "Game.Descriptor.Terrain.h"
#include "Game.Descriptor.Creature.h"
namespace game::Descriptors
{
	const std::string PROPERTY_TYPE = "type";
	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";
	static std::map<std::string, ::game::descriptor::Common*> descriptors;
	static std::vector<std::string> identifiers;

	static std::string ParseKey(const nlohmann::json& key)
	{
		return key;
	}

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	::game::descriptor::Common* ParseDescriptor(const std::string& name, const nlohmann::json& properties)
	{
		const auto& descriptorType = properties[PROPERTY_TYPE];
		if (descriptorType == TYPE_TERRAIN)
		{
			return new ::game::descriptor::Terrain(name, properties);
		}
		else if (descriptorType == TYPE_CREATURE)
		{
			return new ::game::descriptor::Creature(name, properties);
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
		common::Finishers::Add(Finish);
		nlohmann::json properties = data::JSON::Load(filename);
		for (auto& item : properties.items())
		{
			auto identifier = ParseKey(item.key());
			identifiers.push_back(identifier);
			descriptors[identifier] =
				ParseDescriptor(identifier, item.value());
		}
	}

	const ::game::descriptor::Common* Get(const std::string& key)
	{
		return descriptors[key];
	}


}