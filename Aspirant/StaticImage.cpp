#include "StaticImage.h"
#include "Utility.h"
#include "ConstantValue.h"
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
		, spriteName(new ConstantValue<std::string>(properties[PROPERTY_SPRITE]))
		, colorName(new ConstantValue<std::string>(properties[PROPERTY_COLOR]))
		, x(new ConstantValue<int>(properties[PROPERTY_X]))
		, y(new ConstantValue<int>(properties[PROPERTY_Y]))
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
		, spriteName(new ConstantValue(spriteName))
		, colorName(new ConstantValue(colorName))
		, x(new ConstantValue(xy.GetX()))
		, y(new ConstantValue(xy.GetY()))
	{
	}

	StaticImage::~StaticImage()
	{
		Utility::SafeDelete(spriteName);
		Utility::SafeDelete(colorName);
		Utility::SafeDelete(x);
		Utility::SafeDelete(y);
	}


	void StaticImage::Draw(SDL_Renderer* renderer) const
	{
		spriteManager.GetSprite
		(
			spriteName->Get()
		)
			->Draw
		(
			renderer, 
			XY<int>(x->Get(), y->Get()), 
			colorManager.GetDescriptor(colorName->Get())
		);
	}


}
