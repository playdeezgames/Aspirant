#pragma once
#include "XY.h"
#include <string>
#include "SpriteFont.h"
#include "json.hpp"
#include "Drawn.h"
#include "Data.Int.h"
#include "Data.String.h"
#include "Data.Bool.h"
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
		data::Int alignment;
		data::String text;
		data::String fontName;
		data::String color;
		data::String dropShadowColor;
		::data::Bool hasDropShadow;
		data::Int x;
		data::Int y;
		data::Int dropShadowX;
		data::Int dropShadowY;
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
