#pragma once
#include <SDL.h>
#include "XY.h"
namespace tggd::graphics
{
	class Sprite
	{
	private:
		SDL_Texture* texture;
		SDL_Rect source;
		tggd::common::XY<int> offset;
	public:
		Sprite() = default;
		Sprite(const Sprite&) = default;
		Sprite(Sprite&&) = default;
		Sprite& operator=(const Sprite&) = default;
		Sprite& operator=(Sprite&&) = default;
		Sprite(SDL_Texture*, const SDL_Rect&, const tggd::common::XY<int>&);
		void Draw(SDL_Renderer*, const tggd::common::XY<int>&, const SDL_Color&) const;
		void Draw(SDL_Renderer*, const tggd::common::XY<int>&) const;
		int GetWidth() const;
	};
}

