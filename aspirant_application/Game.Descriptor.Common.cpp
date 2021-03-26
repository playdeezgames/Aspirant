#include "Game.Descriptor.Common.h"
#include "Graphics.Sprites.h"
#include "Game.Object.Common.h"
namespace game::descriptor
{
	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		graphics::Sprites::Get(GetSprite()).Draw(renderer, position);
	}

	game::object::Common* Common::CreateObject() const
	{
		return new game::object::Common(GetName());
	}
}
