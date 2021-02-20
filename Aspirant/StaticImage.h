#pragma once
#include "SpriteManager.h"
#include "ColorManager.h"
#include "XY.h"
#include "Drawn.h"
#include "json.hpp"
#include "IValue.h"
#include "IDataStore.h"
namespace tggd::common
{
	class StaticImage : public Drawn
	{
	private:
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
		IValue<std::string>* spriteName;
		IValue<std::string>* colorName;
		IValue<int>* x;
		IValue<int>* y;
	public:
		StaticImage
		(
			const SpriteManager&,
			const ColorManager&,
			const std::string,
			const std::string,
			XY<int>
		);
		StaticImage
		(
			const IDataStore<std::string>&,
			const IDataStore<int>&,
			const SpriteManager&,
			const ColorManager&,
			const nlohmann::json&
		);
		~StaticImage();
		void Draw(SDL_Renderer*) const;
	};
}
