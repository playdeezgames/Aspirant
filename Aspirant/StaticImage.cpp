#include "StaticImage.h"
#include "Utility.h"
#include "ConstantValue.h"
#include "DataUtility.h"
#include "FinishUtility.h"
namespace tggd::common
{
	const std::string PROPERTY_SPRITE = "sprite";
	const std::string PROPERTY_COLOR = "color";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";


	StaticImage::StaticImage
	(
		const tggd::data::IDataStore<std::string>& stringStore,
		const tggd::data::IDataStore<int>& intStore,
		const tggd::data::IDataStore<Sprite>& spriteStore,
		const tggd::data::IDataStore<SDL_Color>& colorStore,
		const nlohmann::json& properties
	)
		: spriteStore(spriteStore)
		, colorStore(colorStore)
		, spriteName(tggd::data::DataUtility::LoadString(stringStore, properties[PROPERTY_SPRITE]))
		, colorName(tggd::data::DataUtility::LoadString(stringStore, properties[PROPERTY_COLOR]))
		, x(tggd::data::DataUtility::LoadInt(intStore, properties[PROPERTY_X]))
		, y(tggd::data::DataUtility::LoadInt(intStore, properties[PROPERTY_Y]))
	{

	}

	StaticImage::StaticImage
	(
		const tggd::data::IDataStore<Sprite>& spriteStore,
		const tggd::data::IDataStore<SDL_Color>& colorStore,
		const std::string spriteName,
		const std::string colorName,
		XY<int> xy
	)
		: spriteStore(spriteStore)
		, colorStore(colorStore)
		, spriteName(new tggd::data::ConstantValue(spriteName))
		, colorName(new tggd::data::ConstantValue(colorName))
		, x(new tggd::data::ConstantValue(xy.GetX()))
		, y(new tggd::data::ConstantValue(xy.GetY()))
	{
	}

	StaticImage::~StaticImage()
	{
		tggd::common::FinishUtility::SafeDelete(spriteName);
		tggd::common::FinishUtility::SafeDelete(colorName);
		tggd::common::FinishUtility::SafeDelete(x);
		tggd::common::FinishUtility::SafeDelete(y);
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
