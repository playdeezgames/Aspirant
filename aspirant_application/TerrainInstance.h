#pragma once
#include "ScenarioObjectInstance.h"
#include "Game.Descriptor.Terrain.h"
namespace aspirant::game
{
	class TerrainInstance : public ScenarioObjectInstance
	{
	public:
		TerrainInstance(const ::game::descriptor::Terrain&);
		bool CanCover(const ScenarioObjectInstance*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
