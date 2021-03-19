#pragma once
#include <SDL.h>
#include "XY.h"
namespace tggd::graphics
{
	class Sprite
	{
		Sprite() = delete;
		Sprite(const Sprite&) = delete;
		Sprite(Sprite&&) = delete;
		Sprite& operator=(const Sprite&) = delete;
		Sprite& operator=(Sprite&&) = delete;
	private:
		SDL_Texture* texture;
		SDL_Rect source;
		tggd::common::XY<int> offset;
	public:
		Sprite(SDL_Texture*, const SDL_Rect&, const tggd::common::XY<int>&);
		void Draw(SDL_Renderer*, const tggd::common::XY<int>&, const SDL_Color&) const;
		void Draw(SDL_Renderer*, const tggd::common::XY<int>&) const;
		int GetWidth() const;
	};
}

