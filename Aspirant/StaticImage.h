#pragma once
#include "SpriteManager.h"
#include "ColorManager.h"
#include "XY.h"
namespace tggd::common
{
	class StaticImage
	{
	private:
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
		std::string spriteName;
		std::string colorName;
		XY<int> xy;
	public:
		StaticImage
		(
			const SpriteManager& spriteManager,
			const ColorManager& colorManager,
			const std::string spriteName,
			const std::string colorName,
			XY<int> xy
		)
			: spriteManager(spriteManager)
			, colorManager(colorManager)
			, spriteName(spriteName)
			, colorName(colorName)
			, xy(xy)
		{

		}
		void Draw(SDL_Renderer* renderer) const
		{
			spriteManager.GetSprite(spriteName)->Draw(renderer, xy, colorManager.GetDescriptor(colorName));
		}
	};
}
