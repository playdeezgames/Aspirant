#pragma once
#include "XY.h"
#include "Drawn.h"
#include "json.hpp"
#include "Sprite.h"
#include "StringSource.h"
#include "IntSource.h"
namespace tggd::graphics
{
	class StaticImage : public Drawn
	{
		StaticImage() = delete;
		StaticImage(const StaticImage&) = delete;
		StaticImage(StaticImage&&) = delete;
		StaticImage& operator=(const StaticImage&) = delete;
		StaticImage& operator=(StaticImage&&) = delete;
	private:
		tggd::data::StringSource spriteName;
		tggd::data::StringSource colorName;
		tggd::data::IntSource x;
		tggd::data::IntSource y;
	public:
		StaticImage
		(
			const std::string,
			const std::string,
			tggd::common::XY<int>
		);
		StaticImage
		(
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
