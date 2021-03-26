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
	{
	}

	void Image::Draw(SDL_Renderer* renderer) const
	{
		Sprites::Get(data::String(model[PROPERTY_SPRITE]))
			.Draw
			(
				renderer,
				common::XY<int>(data::Int(model[PROPERTY_X]), data::Int(model[PROPERTY_X])),
				::graphics::Colors::Get(data::String(model[PROPERTY_COLOR]))
			);
	}
}
