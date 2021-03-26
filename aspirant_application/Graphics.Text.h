#pragma once
#include "Common.XY.h"
#include <string>
#include "Graphics.Font.h"
#include "json.hpp"
#include "Graphics.Drawn.h"
#include "Data.Int.h"
#include "Data.String.h"
#include "Data.Bool.h"
namespace graphics
{
	class Text : public ::graphics::Drawn
	{
		Text() = delete;
		Text(const Text&) = delete;
		Text(Text&&) = delete;
		Text& operator=(const Text&) = delete;
		Text& operator=(Text&&) = delete;
	private:
		data::Int alignment;
		data::String text;
		data::String fontName;
		data::String color;
		data::String dropShadowColor;
		data::Bool hasDropShadow;
		data::Int x;
		data::Int y;
		data::Int dropShadowX;
		data::Int dropShadowY;
		const nlohmann::json& model;
	public:
		Text
		(
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
