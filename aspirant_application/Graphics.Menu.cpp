#include "Data.String.h"
#include "Data.Int.h"
#include "Data.Bool.h"
#include "Graphics.Properties.h"
#include "Graphics.Fonts.h"
#include "Common.Properties.h"
namespace graphics::Menu
{
	void Draw(SDL_Renderer* renderer, const nlohmann::json& model)
	{
		int index = data::Int(model[Properties::INDEX]);
        std::string font = data::String(model[Properties::FONT]);
		std::string activeColor = data::String(model[Properties::COLORS][Properties::ACTIVE]);
		std::string inactiveColor = data::String(model[Properties::COLORS][Properties::INACTIVE]);
		graphics::HorizontalAlignment horizontalAlignment = (graphics::HorizontalAlignment)(int)data::Int(model[Properties::HORIZONTAL_ALIGNMENT]);
		bool dropShadow = data::Bool(model[Properties::DROP_SHADOW]);
		std::string dropShadowColor = data::String(model[Properties::DROP_SHADOW_COLOR]);
		int dropShadowX = data::Int(model[Properties::DROP_SHADOW_X]);
		int dropShadowY = data::Int(model[Properties::DROP_SHADOW_Y]);
		auto& menuItems = model[Properties::MENU_ITEMS];
		int currentIndex = 0;
		for (auto& menuItem : menuItems)
		{
			std::string text = data::String(menuItem[Properties::TEXT]);
			int x = data::Int(menuItem[common::Properties::X]);
			int y = data::Int(menuItem[common::Properties::Y]);
			if (dropShadow)
			{
				Fonts::Get(font).WriteText(renderer, common::XY<int>(x + dropShadowX, y + dropShadowY), text, dropShadowColor, horizontalAlignment);
			}
			std::string color = (currentIndex == index) ? (activeColor) : (inactiveColor);
			Fonts::Get(font).WriteText(renderer, common::XY<int>(x, y), text, color, horizontalAlignment);
			currentIndex++;
		}
	}
}