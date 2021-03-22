#pragma once
#include "Game.Descriptor.Creature.h"
#include "ScenarioObjectInstance.h"
namespace aspirant::game
{
	class CreatureInstance : public ScenarioObjectInstance
	{
	public:
		CreatureInstance(const ::game::descriptor::Creature&);
		bool CanCover(const ScenarioObjectInstance*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
