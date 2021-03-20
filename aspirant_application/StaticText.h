#pragma once
#include "XY.h"
#include <string>
#include "SpriteFont.h"
#include "json.hpp"
#include "Drawn.h"
#include "IntSource.h"
#include "StringSource.h"
#include "BoolSource.h"
namespace tggd::graphics
{
	class StaticText : public Drawn
	{
		StaticText() = delete;
		StaticText(const StaticText&) = delete;
		StaticText(StaticText&&) = delete;
		StaticText& operator=(const StaticText&) = delete;
		StaticText& operator=(StaticText&&) = delete;
	private:
		tggd::data::IntSource alignment;
		tggd::data::StringSource text;
		tggd::data::StringSource fontName;
		tggd::data::StringSource color;
		tggd::data::StringSource dropShadowColor;
		tggd::data::BoolSource hasDropShadow;
		tggd::data::IntSource x;
		tggd::data::IntSource y;
		tggd::data::IntSource dropShadowX;
		tggd::data::IntSource dropShadowY;
	public:
		StaticText
		(
			const tggd::common::XY<int>&,
			const std::string&,
			const std::string&,
			const std::string&,
			bool,
			const tggd::common::XY<int>&,
			const std::string&,
			const HorizontalAlignment&
		);
		StaticText
		(
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
