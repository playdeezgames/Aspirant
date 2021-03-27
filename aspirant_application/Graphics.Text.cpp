#include "Graphics.Text.h"
#include "Common.Utility.h"
#include "Graphics.Fonts.h"
#include "Common.Properties.h"
#include "Graphics.Properties.h"
namespace graphics
{
	Text::Text(const nlohmann::json& model)
		: model(model)
	{
	}

	void Text::Draw(SDL_Renderer* renderer) const
	{
		if (data::Bool(model[graphics::Properties::DROP_SHADOW]))
		{
			graphics::Fonts::Get(
				data::String(model[graphics::Properties::FONT]))
				.WriteText(
					renderer, 
					common::XY<int>(data::Int(model[common::Properties::X]) + data::Int(model[graphics::Properties::DROP_SHADOW_X]), data::Int(model[common::Properties::Y]) + data::Int(model[graphics::Properties::DROP_SHADOW_Y])),
					data::String(model[graphics::Properties::TEXT]),
					data::String(model[graphics::Properties::DROP_SHADOW_COLOR]),
					(HorizontalAlignment)(int)data::Int(model[graphics::Properties::HORIZONTAL_ALIGNMENT]));
		}
		graphics::Fonts::Get(
			data::String(model[graphics::Properties::FONT]))
			.WriteText(
				renderer, 
				common::XY<int>(data::Int(model[common::Properties::X]), data::Int(model[common::Properties::Y])),
				data::String(model[graphics::Properties::TEXT]),
				data::String(model[graphics::Properties::COLOR]),
				(HorizontalAlignment)(int)data::Int(model[graphics::Properties::HORIZONTAL_ALIGNMENT]));
	}
}
