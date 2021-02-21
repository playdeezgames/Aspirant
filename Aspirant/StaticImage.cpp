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
		const IDataStore<std::string>& stringStore,
		const IDataStore<int>& intStore,
		const IDataStore<Sprite>& spriteStore,
		const IDataStore<SDL_Color>& colorStore,
		const nlohmann::json& properties
	)
		: spriteStore(spriteStore)
		, colorStore(colorStore)
		, spriteName(Utility::LoadString(stringStore, properties[PROPERTY_SPRITE]))
		, colorName(Utility::LoadString(stringStore, properties[PROPERTY_COLOR]))
		, x(Utility::LoadInt(intStore, properties[PROPERTY_X]))
		, y(Utility::LoadInt(intStore, properties[PROPERTY_Y]))
	{

	}

	StaticImage::StaticImage
	(
		const IDataStore<Sprite>& spriteStore,
		const IDataStore<SDL_Color>& colorStore,
		const std::string spriteName,
		const std::string colorName,
		XY<int> xy
	)
		: spriteStore(spriteStore)
		, colorStore(colorStore)
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
		spriteStore.Get
		(
			spriteName->Get()
		)
			.Draw
			(
				renderer,
				XY<int>(x->Get(), y->Get()),
				colorStore.Get(colorName->Get())
			);
	}


}
