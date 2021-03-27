#include "Graphics.Image.h"
#include "Common.Utility.h"
#include "Graphics.Sprites.h"
#include "Graphics.Colors.h"
#include "Common.XY.h"
#include "Common.Properties.h"
namespace graphics
{
	const std::string PROPERTY_SPRITE = "sprite";
	const std::string PROPERTY_COLOR = "color";

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
				common::XY<int>(
					data::Int(model[common::Properties::X]), 
					data::Int(model[common::Properties::X])),
				::graphics::Colors::Get(data::String(model[PROPERTY_COLOR]))
			);
	}
}
