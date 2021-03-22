#include "StaticText.h"
#include "Utility.h"
#include "FontManager.h"
namespace tggd::graphics
{
	StaticText::StaticText
	(
		const tggd::common::XY<int>& xy,
		const std::string& text,
		const std::string& fontName,
		const std::string& color,
		bool hasDropShadow,
		const tggd::common::XY<int>& dropShadowOffset,
		const std::string& dropShadowColor,
		const HorizontalAlignment& alignment
	)
		: x(xy.GetX())
		, y(xy.GetY())
		, text(text, false)
		, fontName(fontName, false)
		, color(color, false)
		, hasDropShadow(hasDropShadow)
		, dropShadowX(dropShadowOffset.GetX())
		, dropShadowY(dropShadowOffset.GetY())
		, dropShadowColor(dropShadowColor, false)
		, alignment((int)alignment)
	{

	}

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

	StaticText::StaticText
	(
		const nlohmann::json& properties
	)
		: text(tggd::data::StringSource::FromJSON(properties[PROPERTY_TEXT]))
		, fontName(tggd::data::StringSource::FromJSON(properties[PROPERTY_FONT]))
		, color(tggd::data::StringSource::FromJSON(properties[PROPERTY_COLOR]))
		, x(tggd::data::IntSource::FromJSON(properties[PROPERTY_X]))
		, y(tggd::data::IntSource::FromJSON(properties[PROPERTY_Y]))
		, hasDropShadow(false)
		, dropShadowColor("", false)
		, dropShadowX(0)
		, dropShadowY(0)
		, alignment((int)HorizontalAlignment::LEFT)
	{
		if (properties.count(PROPERTY_DROP_SHADOW) > 0)
		{
			hasDropShadow = ::data::Bool::FromJSON(properties[PROPERTY_DROP_SHADOW]);
		}
		if (properties.count(PROPERTY_HORIZONTAL_ALIGNMENT) > 0)
		{
			alignment = tggd::data::IntSource::FromJSON(properties[PROPERTY_HORIZONTAL_ALIGNMENT]);
		}
		if (properties.count(PROPERTY_DROP_SHADOW) > 0)
		{
			dropShadowColor = tggd::data::StringSource::FromJSON(properties[PROPERTY_DROP_SHADOW_COLOR]);
		}
		if (properties.count(PROPERTY_DROP_SHADOW_X) > 0)
		{
			dropShadowX = tggd::data::IntSource::FromJSON(properties[PROPERTY_DROP_SHADOW_X]);
		}
		if (properties.count(PROPERTY_DROP_SHADOW_Y) > 0)
		{
			dropShadowY = tggd::data::IntSource::FromJSON(properties[PROPERTY_DROP_SHADOW_Y]);
		}
	}

	void StaticText::Draw(SDL_Renderer* renderer) const
	{
		if (hasDropShadow)
		{
			FontManager::Get(fontName).WriteText(renderer, tggd::common::XY<int>(x + dropShadowX, y + dropShadowY), text, dropShadowColor, (HorizontalAlignment)(int)alignment);
		}
		FontManager::Get(fontName).WriteText(renderer, tggd::common::XY<int>(x, y), text, color, (HorizontalAlignment)(int)alignment);
	}
}
