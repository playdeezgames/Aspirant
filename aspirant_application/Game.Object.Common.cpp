#include "Game.Object.Common.h"
#include "Game.Descriptors.h"
#include "Game.Properties.h"
#include "Game.Types.h"
#include "Common.Properties.h"
namespace game::object
{

	Common::Common(nlohmann::json& model)
		: model(model)
	{

	}

	game::descriptor::Common Common::GetDescriptor() const
	{
		return game::Descriptors::Get(model[common::Properties::TYPE]);
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
			return GetType() == game::Types::TERRAIN;
		}
		else if(previous->GetType() == game::Types::TERRAIN)
		{
			return GetType() != game::Types::TERRAIN;
		}
		else
		{
			return false;
		}
	}

	bool Common::IsTerrain() const
	{
		return GetType() == game::Types::TERRAIN;
	}

	bool Common::IsCreature() const
	{
		return GetType() == game::Types::CREATURE || GetType() == game::Types::PLAYER;
	}
}