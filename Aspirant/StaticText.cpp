#include "StaticText.h"
namespace tggd::common
{
	StaticText::StaticText
	(
		const tggd::common::FontManager& fontManager, 
		const tggd::common::XY<int>& xy,
		const std::string& text,
		const std::string& fontName,
		const std::string& color,
		bool hasDropShadow,
		const tggd::common::XY<int>& dropShadowOffset,
		const std::string& dropShadowColor
	)
		: xy(xy)
		, text(text)
		, fontManager(fontManager)
		, fontName(fontName)
		, color(color)
		, hasDropShadow(hasDropShadow)
		, dropShadowXY(dropShadowOffset + xy)
		, dropShadowColor(dropShadowColor)
	{

	}

	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";
	const std::string PROPERTY_TEXT = "text";
	const std::string PROPERTY_FONT = "font";
	const std::string PROPERTY_COLOR = "color";
	const std::string PROPERTY_DROP_SHADOW = "dropShadow";

	StaticText::StaticText
	(
		const tggd::common::FontManager& fontManager, 
		const nlohmann::json& properties
	)
		: xy(properties[PROPERTY_X],properties[PROPERTY_Y])
		, text(properties[PROPERTY_TEXT])
		, fontManager(fontManager)
		, fontName(properties[PROPERTY_FONT])
		, color(properties[PROPERTY_COLOR])//DIFFERENT
		, hasDropShadow(false)
		, dropShadowXY(0,0)
		, dropShadowColor("")
	{
		if (properties.count(PROPERTY_DROP_SHADOW) > 0)
		{
			hasDropShadow = true;
			auto& dropShadow = properties[PROPERTY_DROP_SHADOW];
			dropShadowColor = dropShadow[PROPERTY_COLOR];
			dropShadowXY = xy + XY<int>(dropShadow[PROPERTY_X], dropShadow[PROPERTY_Y]);
		}
	}

	void StaticText::Draw(SDL_Renderer* renderer) const
	{
		if (hasDropShadow)
		{
			fontManager.GetDescriptor(fontName)->WriteText(renderer, dropShadowXY, text, dropShadowColor);
		}
		fontManager.GetDescriptor(fontName)->WriteText(renderer, xy, text, color);//DIFFERENT
	}
}
