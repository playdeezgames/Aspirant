#pragma once
#include "Game.Object.Common.h"
#include "Game.Descriptor.Terrain.h"
namespace game::object
{
	class Terrain : public Common
	{
	public:
		Terrain(const ::game::descriptor::Terrain&);
		bool CanCover(const Common*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
