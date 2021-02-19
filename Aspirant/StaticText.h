#pragma once
#include "XY.h"
#include <string>
#include "FontManager.h"
#include "json.hpp"
namespace tggd::common
{
	class Label
	{
	private:
		tggd::common::XY<int> xy;
		std::string text;
		const tggd::common::FontManager& fontManager;
		std::string fontName;
		std::string color;
		bool hasDropShadow;
		tggd::common::XY<int> dropShadowXY;
		std::string dropShadowColor;
	public:
		Label
		(
			const tggd::common::XY<int>&,
			const std::string&,
			const tggd::common::FontManager&,
			const std::string&,
			const std::string&,
			bool,
			const tggd::common::XY<int>&,
			const std::string&
		);
		Label(const nlohmann::json&);
		void Draw(SDL_Renderer*) const;
	};
}
