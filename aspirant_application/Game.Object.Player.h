#pragma once
#include "Game.Descriptor.Player.h"
#include "Game.Object.Creature.h"
namespace game::object
{
	class Player : public Creature
	{
	public:
		Player(const ::game::descriptor::Player&);
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
