#pragma once
#include "Game.Descriptor.Creature.h"
namespace game::descriptor
{
	class Player : public Creature
	{
	protected:
		Player(const std::string&, const nlohmann::json&);
	public:
		static Common* FromNameAndProperties(const std::string&, const nlohmann::json&);
	};
}
