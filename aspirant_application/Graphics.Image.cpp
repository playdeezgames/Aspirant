#include "Graphics.Image.h"
#include "Common.Utility.h"
#include "Graphics.Sprites.h"
#include "Graphics.Colors.h"
#include "Common.XY.h"
namespace graphics
{
	const std::string PROPERTY_SPRITE = "sprite";
	const std::string PROPERTY_COLOR = "color";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";

	Image::Image
	(
		const nlohmann::json& properties
	)
		: spriteName(::data::String::FromJSON(properties[PROPERTY_SPRITE]))
		, colorName(::data::String::FromJSON(properties[PROPERTY_COLOR]))
		, x(::data::Int::FromJSON(properties[PROPERTY_X]))
		, y(::data::Int::FromJSON(properties[PROPERTY_Y]))
	{
	}

	Image::Image
	(
		const std::string spriteName,
		const std::string colorName,
		common::XY<int> xy
	)
		: spriteName(::data::String(spriteName, false))
		, colorName(::data::String(colorName, false))
		, x(::data::Int(xy.GetX()))
		, y(::data::Int(xy.GetX()))
	{
	}

	void Image::Draw(SDL_Renderer* renderer) const
	{
		Sprites::Get(spriteName)
			.Draw
			(
				renderer,
				common::XY<int>(x,y),
				::graphics::Colors::Get(colorName)
			);
	}
}
