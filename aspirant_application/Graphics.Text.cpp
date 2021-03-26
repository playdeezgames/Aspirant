#include "Graphics.Text.h"
#include "Common.Utility.h"
#include "Graphics.Fonts.h"
namespace graphics
{
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";
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
		, text(model[PROPERTY_TEXT])
		, fontName(model[PROPERTY_FONT])
		, color(model[PROPERTY_COLOR])
		, x(model[PROPERTY_X])
		, y(model[PROPERTY_Y])
		, hasDropShadow(model[PROPERTY_DROP_SHADOW])
		, dropShadowColor(model[PROPERTY_DROP_SHADOW_COLOR])
		, dropShadowX(model[PROPERTY_DROP_SHADOW_X])
		, dropShadowY(model[PROPERTY_DROP_SHADOW_Y])
		, alignment(model[PROPERTY_HORIZONTAL_ALIGNMENT])
	{
	}

	void Text::Draw(SDL_Renderer* renderer) const
	{
		if (hasDropShadow)
		{
			::graphics::Fonts::Get(fontName).WriteText(renderer, common::XY<int>(x + dropShadowX, y + dropShadowY), text, dropShadowColor, (HorizontalAlignment)(int)alignment);
		}
		::graphics::Fonts::Get(fontName).WriteText(renderer, common::XY<int>(x, y), text, color, (HorizontalAlignment)(int)alignment);
	}
}
