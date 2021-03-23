#include "Sprite.h"
namespace tggd::graphics
{
	Sprite::Sprite
	(
		SDL_Texture* texture,
		const SDL_Rect& source,
		const common::XY<int>& offset
	)
		: texture(texture)
		, source(source)
		, offset(offset)
	{

	}

	void Sprite::Draw(SDL_Renderer* renderer, const common::XY<int>& xy) const
	{
		Draw(renderer, xy, { 255,255,255,255 });
	}


	void Sprite::Draw(SDL_Renderer* renderer, const common::XY<int>& xy, const SDL_Color& color) const
	{
		SDL_SetTextureColorMod
		(
			texture,
			color.r,
			color.g,
			color.b
		);
		SDL_SetTextureAlphaMod
		(
			texture,
			color.a
		);
		SDL_Rect rcDst =
		{
			xy.GetX() + offset.GetX(),
			xy.GetY() + offset.GetY(),
			source.w,
			source.h
		};
		SDL_RenderCopy(renderer, texture, &source, &rcDst);
	}

	int Sprite::GetWidth() const
	{
		return source.w;
	}

}
