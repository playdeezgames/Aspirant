#include "Game.Descriptor.Terrain.h"
#include "Game.Object.Common.h"
namespace game::descriptor
{
	Terrain::Terrain(const std::string& name, const nlohmann::json& properties)
		: Common(name, properties)
	{

	}

	Common* Terrain::FromNameAndProperties(const std::string& name, const nlohmann::json& properties)
	{
		return new Terrain(name, properties);
	}
}