#include "CreatureInstance.h"
namespace aspirant::game
{
	CreatureInstance::CreatureInstance(const ::game::descriptor::Creature& descriptor)
		: ScenarioObjectInstance(descriptor)
	{

	}

	bool CreatureInstance::CanCover(const ScenarioObjectInstance* obj) const
	{
		return obj != nullptr && obj->IsTerrain();
	}

	bool CreatureInstance::IsTerrain() const
	{
		return false;
	}

	bool CreatureInstance::IsCreature() const
	{
		return true;
	}

	const std::string PROPERTY_TYPE = "type";

	void CreatureInstance::FromJSON(const nlohmann::json&)
	{

	}

	nlohmann::json CreatureInstance::ToJSON() const
	{
		nlohmann::json properties;
		properties[PROPERTY_TYPE] = GetDescriptor().GetName();//TODO: move this into base class
		return properties;
	}
}