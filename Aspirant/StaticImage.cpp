#include "StaticImage.h"
namespace tggd::common
{
	const std::string PROPERTY_SPRITE = "sprite";
	const std::string PROPERTY_COLOR = "color";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";
	StaticImage::StaticImage
	(
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const nlohmann::json& properties
	)
		: spriteManager(spriteManager)
		, colorManager(colorManager)
		, spriteName(properties[PROPERTY_SPRITE])
		, colorName(properties[PROPERTY_COLOR])
		, xy(properties[PROPERTY_X], properties[PROPERTY_Y])
	{

	}

	StaticImage::StaticImage
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
	void StaticImage::Draw(SDL_Renderer* renderer) const
	{
		spriteManager.GetSprite(spriteName)->Draw(renderer, xy, colorManager.GetDescriptor(colorName));
	}


}
