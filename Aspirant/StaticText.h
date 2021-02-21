#pragma once
#include "XY.h"
#include <string>
#include "IDataStore.h"
#include "SpriteFont.h"
#include "json.hpp"
#include "Drawn.h"
namespace tggd::common
{
	class StaticText: public Drawn
	{
	private:
		tggd::common::XY<int> xy;
		std::string text;
		const tggd::common::IDataStore<SpriteFont>& fontStore;
		std::string fontName;
		std::string color;
		bool hasDropShadow;
		tggd::common::XY<int> dropShadowXY;
		std::string dropShadowColor;
	public:
		StaticText
		(
			const tggd::common::IDataStore<SpriteFont>&,
			const tggd::common::XY<int>&,
			const std::string&,
			const std::string&,
			const std::string&,
			bool,
			const tggd::common::XY<int>&,
			const std::string&
		);
		StaticText
		(
			const tggd::common::IDataStore<std::string>&,
			const tggd::common::IDataStore<int>&,
			const tggd::common::IDataStore<SpriteFont>&,
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
