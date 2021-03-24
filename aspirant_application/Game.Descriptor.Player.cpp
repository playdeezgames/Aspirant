#include "Game.Descriptor.Player.h"
#include "Game.Object.Player.h"
namespace game::descriptor
{
	Player::Player(const std::string& name, const nlohmann::json& properties)
		: Creature(name, properties)
	{

	}

	game::object::Common* Player::CreateObject() const
	{
		return new game::object::Player(*this);
	}
	
	Common* Player::FromNameAndProperties(const std::string& name, const nlohmann::json& properties)
	{
		return new Player(name, properties);
	}
}
