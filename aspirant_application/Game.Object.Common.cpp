#include "Game.Object.Common.h"
#include "Game.Descriptors.h"
namespace game::object
{
	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";
	const std::string TYPE_PLAYER = "player";
	const std::string PROPERTY_TYPE = "type";

	Common::Common(nlohmann::json& model)
		: model(model)
	{

	}

	game::descriptor::Common Common::GetDescriptor() const
	{
		return game::Descriptors::Get(model[PROPERTY_TYPE]);
	}

	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		GetDescriptor().Draw(renderer, position);
	}


	std::string Common::GetType() const
	{
		return GetDescriptor().GetType();
	}

	bool Common::CanCover(std::optional<Common> previous) const
	{
		if (!previous.has_value())
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
}