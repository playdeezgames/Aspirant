#include "Game.Descriptor.Common.h"
#include "Graphics.Sprites.h"
#include "Game.Object.Common.h"
namespace game::descriptor
{
	const std::string PROPERTY_TYPE = "type";
	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		graphics::Sprites::Get(GetSprite()).Draw(renderer, position);
	}

	game::object::Common Common::CreateObject(nlohmann::json& model) const
	{
		model[PROPERTY_TYPE] = GetName();
		return game::object::Common(model);
	}
}
