#include "TerrainInstance.h"
namespace aspirant
{
	TerrainInstance::TerrainInstance(const TerrainDescriptor& descriptor)
		: ScenarioObjectInstance(descriptor)
	{

	}

	bool TerrainInstance::CanCover(const ScenarioObjectInstance* obj) const
	{
		return obj == nullptr;
	}

	bool TerrainInstance::IsTerrain() const
	{
		return true;
	}

	bool TerrainInstance::IsCreature() const
	{
		return false;
	}

	void TerrainInstance::FromJSON(const nlohmann::json&)
	{

	}
}