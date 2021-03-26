#include "Game.Descriptor.Creature.h"
#include "Game.Object.Common.h"
namespace game::descriptor
{
	Creature::Creature(const std::string& name, const nlohmann::json& properties)
		: Common(name, properties)
	{

	}

	game::object::Common* Creature::CreateObject() const
	{
		return new game::object::Common(GetName());
	}

	Common* Creature::FromNameAndProperties(const std::string& name, const nlohmann::json& properties)
	{
		return new Creature(name, properties);
	}
}