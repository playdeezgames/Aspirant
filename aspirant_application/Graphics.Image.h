#pragma once
#include "Common.XY.h"
#include "Graphics.Drawn.h"
#include "json.hpp"
#include "Graphics.Sprite.h"
#include "Data.String.h"
#include "Data.Int.h"
namespace graphics
{
	class Image : public ::graphics::Drawn
	{
		Image() = delete;
		Image(const Image&) = delete;
		Image(Image&&) = delete;
		Image& operator=(const Image&) = delete;
		Image& operator=(Image&&) = delete;
	private:
		::data::String spriteName;
		::data::String colorName;
		::data::Int x;
		::data::Int y;
	public:
		Image
		(
			const std::string,
			const std::string,
			common::XY<int>
		);
		Image
		(
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
