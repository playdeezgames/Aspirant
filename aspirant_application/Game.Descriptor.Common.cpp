#include "Game.Descriptor.Common.h"
#include "Graphics.Sprites.h"
#include "Game.Object.Common.h"
#include "Game.Properties.h"
#include "Common.Properties.h"
namespace game::descriptor
{
	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		graphics::Sprites::Get(GetSprite()).Draw(renderer, position);
	}

	game::object::Common Common::CreateObject(nlohmann::json& model) const
	{
		model[common::Properties::TYPE] = GetName();
		return game::object::Common(model);
	}
}
