#pragma once
#include "Game.Descriptor.Creature.h"
#include "Game.Object.Common.h"
namespace game::object
{
	class Creature : public Common
	{
	public:
		Creature(const ::game::descriptor::Creature&);
		bool CanCover(const Common*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
