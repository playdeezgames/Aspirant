#pragma once
#include "Drawn.h"
#include "FinishManager.h"
#include <list>
#include "json.hpp"
#include "SpriteManager.h"
#include "Graphics.Colors.h"
#include "FontManager.h"
namespace tggd::graphics
{
	class Layout
		: public Drawn
	{
		Layout() = delete;
		Layout(const Layout&) = delete;
		Layout(Layout&&) = delete;
		Layout& operator=(const Layout&) = delete;
		Layout& operator=(Layout&&) = delete;
	private:
		std::list<Drawn*> drawnItems;
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
