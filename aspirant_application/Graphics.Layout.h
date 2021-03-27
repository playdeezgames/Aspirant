#pragma once
#include "Graphics.Drawn.h"
#include "Common.Finishers.h"
#include <list>
#include "json.hpp"
#include "Graphics.Sprites.h"
#include "Graphics.Colors.h"
#include "Graphics.Fonts.h"
namespace graphics
{
	class Layout
		: public ::graphics::Drawn
	{
		Layout() = delete;
		Layout(const Layout&) = delete;
		Layout(Layout&&) = delete;
		Layout& operator=(const Layout&) = delete;
		Layout& operator=(Layout&&) = delete;
	private:
		nlohmann::json& model;
	public:
		Layout
		(
			nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
