#pragma once
#include "ScenarioObjectInstance.h"
#include "TerrainDescriptor.h"
namespace aspirant
{
	class TerrainInstance : public ScenarioObjectInstance
	{
	public:
		TerrainInstance(const TerrainDescriptor&);
		bool CanCover(const ScenarioObjectInstance*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);
	};
}
