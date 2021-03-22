#include "TerrainInstance.h"
namespace aspirant::game
{
	TerrainInstance::TerrainInstance(const ::game::descriptor::Terrain& descriptor)
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

	const std::string PROPERTY_TYPE = "type";

	void TerrainInstance::FromJSON(const nlohmann::json&)
	{

	}

	nlohmann::json TerrainInstance::ToJSON() const
	{
		nlohmann::json properties;
		properties[PROPERTY_TYPE] = GetDescriptor().GetName();//TODO: move this into base class
		return properties;
	}
}