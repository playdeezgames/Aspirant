#pragma once
#include "XY.h"
#include <string>
#include "FontManager.h"
#include "StringManager.h"
#include "json.hpp"
#include "Drawn.h"
namespace tggd::common
{
	class TintableText : public Drawn
	{
	private:
		tggd::common::XY<int> xy;
		std::string text;
		const tggd::common::FontManager& fontManager;
		const tggd::common::StringManager& stringManager;
		std::string colorStringName;
		std::string fontName;
		bool hasDropShadow;
		tggd::common::XY<int> dropShadowXY;
		std::string dropShadowColor;
	public:
		TintableText
		(
			const tggd::common::FontManager&,
			const tggd::common::StringManager&,
			const tggd::common::XY<int>&,
			const std::string&,
			const std::string&,
			const std::string&,
			bool,
			const tggd::common::XY<int>&,
			const std::string&
		);
		TintableText(const tggd::common::FontManager&, const tggd::common::StringManager&, const nlohmann::json&);
		void Draw(SDL_Renderer*) const;
	};
}
