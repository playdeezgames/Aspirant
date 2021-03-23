#pragma once
#include "Graphics.Drawn.h"
#include "Common.Finishers.h"
#include <list>
#include "json.hpp"
#include "SpriteManager.h"
#include "Graphics.Colors.h"
#include "FontManager.h"
namespace tggd::graphics
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
		std::list<::graphics::Drawn*> drawnItems;
	public:
		Layout
		(
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
		void Finish();
		void Add(Drawn*);
	};
}
