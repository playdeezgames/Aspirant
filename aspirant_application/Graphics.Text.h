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
		const nlohmann::json& model;
	public:
		Text
		(
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
