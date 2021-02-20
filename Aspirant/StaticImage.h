#pragma once
#include "SpriteManager.h"
#include "ColorManager.h"
#include "XY.h"
#include "Drawn.h"
#include "json.hpp"
namespace tggd::common
{
	class StaticImage : public Drawn
	{
	private:
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
		std::string spriteName;
		std::string colorName;
		XY<int> xy;
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
			const SpriteManager&,
			const ColorManager&,
			const nlohmann::json&
		);
		void Draw(SDL_Renderer*) const;
	};
}
