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
		, spriteName(model[PROPERTY_SPRITE])
		, colorName(model[PROPERTY_COLOR])
		, x(model[PROPERTY_X])
		, y(model[PROPERTY_Y])
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
