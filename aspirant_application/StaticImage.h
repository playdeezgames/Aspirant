#pragma once
#include "Common.XY.h"
#include "Graphics.Drawn.h"
#include "json.hpp"
#include "Sprite.h"
#include "Data.String.h"
#include "Data.Int.h"
namespace tggd::graphics
{
	class StaticImage : public ::graphics::Drawn
	{
		StaticImage() = delete;
		StaticImage(const StaticImage&) = delete;
		StaticImage(StaticImage&&) = delete;
		StaticImage& operator=(const StaticImage&) = delete;
		StaticImage& operator=(StaticImage&&) = delete;
	private:
		::data::String spriteName;
		::data::String colorName;
		::data::Int x;
		::data::Int y;
	public:
		StaticImage
		(
			const std::string,
			const std::string,
			common::XY<int>
		);
		StaticImage
		(
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
