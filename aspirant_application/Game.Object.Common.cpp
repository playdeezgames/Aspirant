#include "Game.Object.Common.h"
namespace game::object
{
	void Common::Draw(SDL_Renderer* renderer, common::XY<int> position) const
	{
		GetDescriptor().Draw(renderer, position);
	}
}