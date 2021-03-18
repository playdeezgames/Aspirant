#pragma once
#include "XY.h"
#include <string>
#include "IDataStore.h"
#include "IValue.h"
#include "SpriteFont.h"
#include "json.hpp"
#include "Drawn.h"
namespace tggd::graphics
{
	class StaticText: public Drawn
	{
	private:
		const tggd::data::IDataStore<SpriteFont>& fontStore;

		tggd::data::IValue<int>* alignment;
		tggd::data::IValue<std::string>* text;
		tggd::data::IValue<std::string>* fontName;
		tggd::data::IValue<std::string>* color;
		tggd::data::IValue<std::string>* dropShadowColor;
		tggd::data::IValue<bool>* hasDropShadow;
		tggd::data::IValue<int>* x;
		tggd::data::IValue<int>* y;
		tggd::data::IValue<int>* dropShadowX;
		tggd::data::IValue<int>* dropShadowY;
	public:
		StaticText
		(
			const tggd::data::IDataStore<SpriteFont>&,
			const tggd::common::XY<int>&,
			const std::string&,
			const std::string&,
			const std::string&,
			bool,
			const tggd::common::XY<int>&,
			const std::string&,
			const HorizontalAlignment&
		);
		StaticText
		(
			const tggd::data::IDataStore<std::string>&,
			const tggd::data::IDataStore<int>&,
			const tggd::data::IDataStore<bool>&,
			const tggd::data::IDataStore<SpriteFont>&,
			const nlohmann::json&
		);
		~StaticText();
		void Draw(SDL_Renderer*) const;
	};
}
