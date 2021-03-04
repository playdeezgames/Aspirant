#include "DescriptorManager.h"
#include "TerrainDescriptor.h"
#include "CreatureDescriptor.h"
namespace aspirant
{
	const std::string PROPERTY_TYPE = "type";
	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";
	BaseDescriptor<ScenarioObjectInstance>* DescriptorManager::ParseDescriptor(const nlohmann::json& properties)
	{
		const auto& descriptorType = properties[PROPERTY_TYPE];
		if (descriptorType == TYPE_TERRAIN)
		{
			return new TerrainDescriptor(properties);
		}
		else if (descriptorType == TYPE_CREATURE)
		{
			return new CreatureDescriptor(properties);
		}
		else
		{
			throw "INVALID DESCRIPTOR TYPE";
		}
	}
}