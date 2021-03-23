#include "Game.Object.Terrain.h"
namespace game::object
{
	Terrain::Terrain(const ::game::descriptor::Terrain& descriptor)
		: Common(descriptor)
	{

	}

	bool Terrain::CanCover(const Common* obj) const
	{
		return obj == nullptr;
	}

	bool Terrain::IsTerrain() const
	{
		return true;
	}

	bool Terrain::IsCreature() const
	{
		return false;
	}

	const std::string PROPERTY_TYPE = "type";

	void Terrain::FromJSON(const nlohmann::json&)
	{

	}

	nlohmann::json Terrain::ToJSON() const
	{
		nlohmann::json properties;
		properties[PROPERTY_TYPE] = GetDescriptor().GetName();//TODO: move this into base class
		return properties;
	}
}