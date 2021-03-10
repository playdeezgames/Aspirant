#pragma once
#include "Drawn.h"
#include "FinishManager.h"
#include <list>
#include "json.hpp"
#include "SpriteManager.h"
#include "ColorManager.h"
#include "FontManager.h"
#include "IDataStore.h"
namespace tggd::common
{
	class Layout: public Drawn, public Finisher
	{
	private:
		std::list<Drawn*> drawnItems;
	public:
		Layout
		(
			FinishManager&
		);
		Layout
		(
			FinishManager&,
			const SpriteManager&,
			const ColorManager&,
			const FontManager&,
			const tggd::data::IDataStore<std::string>&,
			const tggd::data::IDataStore<int>&,
			const tggd::data::IDataStore<bool>&,
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
		void Finish();
		void Add(Drawn*);
	};
}
