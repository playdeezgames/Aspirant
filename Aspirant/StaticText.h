#pragma once
#include "XY.h"
#include <string>
#include "IDataStore.h"
#include "IValue.h"
#include "SpriteFont.h"
#include "json.hpp"
#include "Drawn.h"
namespace tggd::common
{
	class StaticText: public Drawn
	{
	private:
		const tggd::common::IDataStore<SpriteFont>& fontStore;

		IValue<std::string>* text;
		IValue<std::string>* fontName;
		IValue<std::string>* color;
		IValue<std::string>* dropShadowColor;
		IValue<bool>* hasDropShadow;
		IValue<int>* x;
		IValue<int>* y;
		IValue<int>* dropShadowX;
		IValue<int>* dropShadowY;
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
			const tggd::common::IDataStore<bool>&,
			const tggd::common::IDataStore<SpriteFont>&,
			const nlohmann::json&
		);
		~StaticText();
		void Draw(SDL_Renderer*) const;
	};
}
