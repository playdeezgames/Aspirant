#include "Game.Descriptor.Terrain.h"
#include "TerrainInstance.h"
namespace game::descriptor
{
	Terrain::Terrain(const std::string& name, const nlohmann::json& properties)
		: Common(name, properties)
	{

	}

	aspirant::game::ScenarioObjectInstance* Terrain::CreateObject() const
	{
		return new aspirant::game::TerrainInstance(*this);
	}

}