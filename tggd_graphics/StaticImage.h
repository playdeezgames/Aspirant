#pragma once
#include "XY.h"
#include "Drawn.h"
#include "json.hpp"
#include "IValue.h"
#include "IDataStore.h"
#include "Sprite.h"
namespace tggd::graphics
{
	class StaticImage : public Drawn
	{
	private:
		const tggd::data::IDataStore<Sprite>& spriteStore;
		const tggd::data::IDataStore<SDL_Color>& colorStore;

		tggd::data::IValue<std::string>* spriteName;
		tggd::data::IValue<std::string>* colorName;
		tggd::data::IValue<int>* x;
		tggd::data::IValue<int>* y;
	public:
		StaticImage
		(
			const tggd::data::IDataStore<Sprite>&,
			const tggd::data::IDataStore<SDL_Color>&,
			const std::string,
			const std::string,
			XY<int>
		);
		StaticImage
		(
			const tggd::data::IDataStore<std::string>&,
			const tggd::data::IDataStore<int>&,
			const tggd::data::IDataStore<Sprite>&,
			const tggd::data::IDataStore<SDL_Color>&,
			const nlohmann::json&
		);
		~StaticImage();
		void Draw(SDL_Renderer*) const;
	};
}
