#include "DynamicText.h"
namespace tggd::common
{
	DynamicText::DynamicText
	(
		const tggd::common::FontManager& fontManager,
		const tggd::common::StringManager& stringManager,
		const tggd::common::XY<int>& xy,
		const std::string& text,
		const std::string& fontName,
		const std::string& colorStringName,
		bool hasDropShadow,
		const tggd::common::XY<int>& dropShadowXY,
		const std::string& dropShadowColor
	)
		: fontManager(fontManager)
		, stringManager(stringManager)
		, xy(xy)
		, text(text)
		, fontName(fontName)
		, colorStringName(colorStringName)
		, hasDropShadow(hasDropShadow)
		, dropShadowXY(xy + dropShadowXY)
		, dropShadowColor(dropShadowColor)
	{
	}

	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";
	const std::string PROPERTY_TEXT = "text";
	const std::string PROPERTY_FONT = "font";
	const std::string PROPERTY_COLOR_STRING = "color";
	const std::string PROPERTY_DROP_SHADOW = "dropShadow";
	const std::string PROPERTY_COLOR = "color";

	DynamicText::DynamicText
	(
		const tggd::common::FontManager& fontManager, 
		const tggd::common::StringManager& stringManager, const nlohmann::json& properties
	)
		: fontManager(fontManager)
		, stringManager(stringManager)//DIFFERENT
		, xy(properties[PROPERTY_X], properties[PROPERTY_Y])
		, text(properties[PROPERTY_TEXT])
		, fontName(properties[PROPERTY_FONT])
		, colorStringName(properties[PROPERTY_COLOR_STRING])//DIFFERENT
		, hasDropShadow(false)
		, dropShadowXY(0, 0)
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

	void DynamicText::Draw(SDL_Renderer* renderer) const
	{
		if (hasDropShadow)
		{
			fontManager.GetDescriptor(fontName)->WriteText(renderer, dropShadowXY, text, dropShadowColor);
		}
		fontManager.GetDescriptor(fontName)->WriteText(renderer, xy, text, stringManager.Get(colorStringName));
	}

}