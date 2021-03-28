#include "Game.Descriptor.Common.h"
#include "Graphics.Sprites.h"
#include "Game.Object.Common.h"
#include "Game.Properties.h"
#include "Common.Properties.h"
#include "Game.Types.h"
namespace game::descriptor
{
	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		graphics::Sprites::Read(GetSprite()).value().Draw(renderer, position);
	}

	game::object::Common Common::CreateObject(nlohmann::json& model) const
	{
		model[common::Properties::TYPE] = GetName();
		return game::object::Common(model);
	}

	bool Common::CanCover(std::optional<game::object::Common> previous) const
	{
		if (!previous.has_value())
		{
			return GetType() == game::Types::TERRAIN;
		}
		else if (previous->GetType() == game::Types::TERRAIN)
		{
			return GetType() != game::Types::TERRAIN;
		}
		else
		{
			return false;
		}
	}
}
