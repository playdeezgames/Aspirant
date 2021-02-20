#include "StaticText.h"
namespace tggd::common
{
	StaticText::StaticText
	(
		const tggd::common::XY<int>& xy,
		const std::string& text,
		const tggd::common::FontManager& fontManager, 
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
	void StaticText::Draw(SDL_Renderer* renderer) const
	{
		if (hasDropShadow)
		{
			fontManager.GetDescriptor(fontName)->WriteText(renderer, dropShadowXY, text, dropShadowColor);
		}
		fontManager.GetDescriptor(fontName)->WriteText(renderer, xy, text, color);
	}
}
