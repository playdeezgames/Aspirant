#include "Graphics.Text.h"
#include "Common.Utility.h"
#include "Graphics.Fonts.h"
#include "Common.Properties.h"
namespace graphics
{
	const std::string PROPERTY_TEXT = "text";
	const std::string PROPERTY_FONT = "font";
	const std::string PROPERTY_COLOR = "color";
	const std::string PROPERTY_DROP_SHADOW = "dropShadow";
	const std::string PROPERTY_DROP_SHADOW_COLOR = "dropShadowColor";
	const std::string PROPERTY_DROP_SHADOW_X = "dropShadowX";
	const std::string PROPERTY_DROP_SHADOW_Y = "dropShadowY";
	const std::string PROPERTY_HORIZONTAL_ALIGNMENT = "horizontalAlignment";

	Text::Text(const nlohmann::json& model)
		: model(model)
	{
	}

	void Text::Draw(SDL_Renderer* renderer) const
	{
		if (data::Bool(model[PROPERTY_DROP_SHADOW]))
		{
			graphics::Fonts::Get(
				data::String(model[PROPERTY_FONT]))
				.WriteText(
					renderer, 
					common::XY<int>(data::Int(model[common::Properties::X]) + data::Int(model[PROPERTY_DROP_SHADOW_X]), data::Int(model[common::Properties::Y]) + data::Int(model[PROPERTY_DROP_SHADOW_Y])),
					data::String(model[PROPERTY_TEXT]),
					data::String(model[PROPERTY_DROP_SHADOW_COLOR]),
					(HorizontalAlignment)(int)data::Int(model[PROPERTY_HORIZONTAL_ALIGNMENT]));
		}
		graphics::Fonts::Get(
			data::String(model[PROPERTY_FONT]))
			.WriteText(
				renderer, 
				common::XY<int>(data::Int(model[common::Properties::X]), data::Int(model[common::Properties::Y])),
				data::String(model[PROPERTY_TEXT]),
				data::String(model[PROPERTY_COLOR]),
				(HorizontalAlignment)(int)data::Int(model[PROPERTY_HORIZONTAL_ALIGNMENT]));
	}
}
