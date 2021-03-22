#include "StaticImage.h"
#include "Utility.h"
#include "SpriteManager.h"
#include "Graphics.Colors.h"
#include "XY.h"
namespace tggd::graphics
{
	const std::string PROPERTY_SPRITE = "sprite";
	const std::string PROPERTY_COLOR = "color";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";

	StaticImage::StaticImage
	(
		const nlohmann::json& properties
	)
		: spriteName(::data::String::FromJSON(properties[PROPERTY_SPRITE]))
		, colorName(::data::String::FromJSON(properties[PROPERTY_COLOR]))
		, x(::data::Int::FromJSON(properties[PROPERTY_X]))
		, y(::data::Int::FromJSON(properties[PROPERTY_Y]))
	{
	}

	StaticImage::StaticImage
	(
		const std::string spriteName,
		const std::string colorName,
		tggd::common::XY<int> xy
	)
		: spriteName(::data::String(spriteName, false))
		, colorName(::data::String(colorName, false))
		, x(::data::Int(xy.GetX()))
		, y(::data::Int(xy.GetX()))
	{
	}

	void StaticImage::Draw(SDL_Renderer* renderer) const
	{
		SpriteManager::Get(spriteName)
			.Draw
			(
				renderer,
				tggd::common::XY<int>(x,y),
				::graphics::Colors::Get(colorName)
			);
	}
}
