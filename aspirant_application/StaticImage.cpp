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
		: spriteName(tggd::data::StringSource::FromJSON(properties[PROPERTY_SPRITE]))
		, colorName(tggd::data::StringSource::FromJSON(properties[PROPERTY_COLOR]))
		, x(tggd::data::IntSource::FromJSON(properties[PROPERTY_X]))
		, y(tggd::data::IntSource::FromJSON(properties[PROPERTY_Y]))
	{
	}

	StaticImage::StaticImage
	(
		const std::string spriteName,
		const std::string colorName,
		tggd::common::XY<int> xy
	)
		: spriteName(tggd::data::StringSource(spriteName, false))
		, colorName(tggd::data::StringSource(colorName, false))
		, x(tggd::data::IntSource(xy.GetX()))
		, y(tggd::data::IntSource(xy.GetX()))
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
