#include "Game.Object.Common.h"
#include "Game.Descriptors.h"
namespace game::object
{
	game::descriptor::Common Common::GetDescriptor() const
	{
		return game::Descriptors::Get(descriptorName);
	}

	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		GetDescriptor().Draw(renderer, position);
	}

	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";
	const std::string TYPE_PLAYER = "player";
	const std::string PROPERTY_TYPE = "type";

	std::string Common::GetType() const
	{
		return GetDescriptor().GetType();
	}

	bool Common::CanCover(const Common* previous) const
	{
		if (!previous)
		{
			return GetType() == TYPE_TERRAIN;
		}
		else if(previous->GetType() == TYPE_TERRAIN)
		{
			return GetType() != TYPE_TERRAIN;
		}
		else
		{
			return false;
		}
	}

	bool Common::IsTerrain() const
	{
		return GetType() == TYPE_TERRAIN;
	}

	bool Common::IsCreature() const
	{
		return GetType() == TYPE_CREATURE || GetType() == TYPE_PLAYER;
	}

	void Common::FromJSON(const nlohmann::json& properties)
	{
		descriptorName = properties[PROPERTY_TYPE];
	}

	nlohmann::json Common::ToJSON() const
	{
		nlohmann::json properties;
		properties[PROPERTY_TYPE] = GetDescriptor().GetName();
		return properties;
	}
}