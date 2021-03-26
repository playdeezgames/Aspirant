#include "Game.Descriptor.Player.h"
#include "Game.Object.Common.h"
namespace game::descriptor
{
	Player::Player(const std::string& name, const nlohmann::json& properties)
		: Creature(name, properties)
	{

	}

	Common* Player::FromNameAndProperties(const std::string& name, const nlohmann::json& properties)
	{
		return new Player(name, properties);
	}
}
