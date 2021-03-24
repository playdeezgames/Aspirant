#include "Game.Descriptors.h"
#include "Common.Finishers.h"
#include <map>
#include "Common.Finisher.h"
#include "Data.JSON.h"
#include "Game.Descriptor.Terrain.h"
#include "Game.Descriptor.Creature.h"
#include "Game.Descriptor.Player.h"
namespace game::Descriptors
{
	const std::string PROPERTY_TYPE = "type";
	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";
	const std::string TYPE_PLAYER = "player";
	static std::map<std::string, ::game::descriptor::Common*> descriptors;
	static std::vector<std::string> identifiers;
	typedef game::descriptor::Common* (*DescriptorFactory)(const std::string&, const nlohmann::json&);

	static std::string ParseKey(const nlohmann::json& key)
	{
		return key;
	}

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	static std::map<std::string, DescriptorFactory> factories =
	{
		{TYPE_TERRAIN, game::descriptor::Terrain::FromNameAndProperties},
		{TYPE_CREATURE, game::descriptor::Creature::FromNameAndProperties},
		{TYPE_PLAYER, game::descriptor::Player::FromNameAndProperties}
	};

	::game::descriptor::Common* ParseDescriptor(const std::string& name, const nlohmann::json& properties)
	{
		return factories[properties[PROPERTY_TYPE]](name, properties);
	}

	static void Finish()
	{
		common::Finisher::SafeDeleteMap(descriptors);
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