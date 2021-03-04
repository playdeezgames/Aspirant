#pragma once
#include "ScenarioObjectInstance.h"
#include "CreatureDescriptor.h"
namespace aspirant
{
	class CreatureInstance : public ScenarioObjectInstance
	{
	public:
		CreatureInstance(const CreatureDescriptor&);
		bool CanCover(const ScenarioObjectInstance*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);

	};
}
