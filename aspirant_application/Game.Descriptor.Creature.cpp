#include "Game.Descriptor.Creature.h"
#include "CreatureInstance.h"
namespace game::descriptor
{
	Creature::Creature(const std::string& name, const nlohmann::json& properties)
		: Common(name, properties)
	{

	}

	aspirant::game::ScenarioObjectInstance* Creature::CreateObject() const
	{
		return new aspirant::game::CreatureInstance(*this);
	}

}