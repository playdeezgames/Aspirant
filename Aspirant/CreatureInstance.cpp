#include "CreatureInstance.h"
namespace aspirant
{
	CreatureInstance::CreatureInstance(const CreatureDescriptor& descriptor)
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

	void CreatureInstance::FromJSON(const nlohmann::json&)
	{

	}
}