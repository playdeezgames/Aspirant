#include "Game.Descriptor.Creature.h"
#include "Game.Object.Common.h"
namespace game::descriptor
{
	Creature::Creature(const std::string& name, const nlohmann::json& properties)
		: Common(name, properties)
	{

	}

	Common* Creature::FromNameAndProperties(const std::string& name, const nlohmann::json& properties)
	{
		return new Creature(name, properties);
	}
}