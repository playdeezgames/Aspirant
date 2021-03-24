#include "Game.Object.Player.h"
namespace game::object
{
	Player::Player(const ::game::descriptor::Player& descriptor)
		: Creature(descriptor)
	{

	}

	void Player::FromJSON(const nlohmann::json& properties)
	{
		Creature::FromJSON(properties);
	}

	nlohmann::json Player::ToJSON() const
	{
		return Creature::ToJSON();
	}
}
