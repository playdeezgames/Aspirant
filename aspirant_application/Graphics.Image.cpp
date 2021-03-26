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

	Image::Image(const nlohmann::json& model)
		: model(model)
		, spriteName(::data::String::FromJSON(model[PROPERTY_SPRITE]))
		, colorName(::data::String::FromJSON(model[PROPERTY_COLOR]))
		, x(::data::Int::FromJSON(model[PROPERTY_X]))
		, y(::data::Int::FromJSON(model[PROPERTY_Y]))
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
