#include "Game.Descriptor.Terrain.h"
#include "Game.Object.Terrain.h"
namespace game::descriptor
{
	Terrain::Terrain(const std::string& name, const nlohmann::json& properties)
		: Common(name, properties)
	{

	}

	game::object::Common* Terrain::CreateObject() const
	{
		return new ::game::object::Terrain(*this);
	}

	Common* Terrain::FromNameAndProperties(const std::string& name, const nlohmann::json& properties)
	{
		return new Terrain(name, properties);
	}
}