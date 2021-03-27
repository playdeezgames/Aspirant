#include "Graphics.Image.h"
#include "Common.Utility.h"
#include "Graphics.Sprites.h"
#include "Graphics.Colors.h"
#include "Common.XY.h"
#include "Common.Properties.h"
#include "Graphics.Properties.h"
namespace graphics
{
	Image::Image(const nlohmann::json& model)
		: model(model)
	{
	}

	void Image::Draw(SDL_Renderer* renderer) const
	{
		Sprites::Get(data::String(model[Properties::SPRITE]))
			.Draw
			(
				renderer,
				common::XY<int>(
					data::Int(model[common::Properties::X]), 
					data::Int(model[common::Properties::X])),
				::graphics::Colors::Get(data::String(model[Properties::COLOR]))
			);
	}
}
