#pragma once
#include "XY.h"
#include "Drawn.h"
#include "json.hpp"
#include "IValue.h"
#include "IDataStore.h"
#include "Sprite.h"
namespace tggd::common
{
	class StaticImage : public Drawn
	{
	private:
		const IDataStore<Sprite>& spriteStore;
		const IDataStore<SDL_Color>& colorStore;

		IValue<std::string>* spriteName;
		IValue<std::string>* colorName;
		IValue<int>* x;
		IValue<int>* y;
	public:
		StaticImage
		(
			const IDataStore<Sprite>&,
			const IDataStore<SDL_Color>&,
			const std::string,
			const std::string,
			XY<int>
		);
		StaticImage
		(
			const IDataStore<std::string>&,
			const IDataStore<int>&,
			const IDataStore<Sprite>&,
			const IDataStore<SDL_Color>&,
			const nlohmann::json&
		);
		~StaticImage();
		void Draw(SDL_Renderer*) const;
	};
}
