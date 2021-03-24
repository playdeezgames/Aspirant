#include "Game.Descriptor.Common.h"
#include "Graphics.Sprites.h"
namespace game::descriptor
{
	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		graphics::Sprites::Get(GetSprite()).Draw(renderer, position);
	}
}
