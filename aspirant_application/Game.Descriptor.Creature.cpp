#include "Game.Descriptor.Creature.h"
#include "Game.Object.Creature.h"
namespace game::descriptor
{
	Creature::Creature(const std::string& name, const nlohmann::json& properties)
		: Common(name, properties)
	{

	}

	game::object::Common* Creature::CreateObject() const
	{
		return new game::object::Creature(*this);
	}

}