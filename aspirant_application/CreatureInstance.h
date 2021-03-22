#pragma once
#include "ScenarioObjectInstance.h"
#include "Game.Descriptor.Creature.h"
namespace aspirant::game
{
	class CreatureInstance : public ScenarioObjectInstance
	{
	public:
		CreatureInstance(const CreatureDescriptor&);
		bool CanCover(const ScenarioObjectInstance*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
