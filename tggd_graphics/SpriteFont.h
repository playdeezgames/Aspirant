#pragma once
#include "SpriteManager.h"
#include <string>
#include <map>
#include "XY.h"
#include "ColorManager.h"
namespace tggd::graphics
{
	enum class HorizontalAlignment
	{
		RIGHT = -1,
		CENTER = 0,
		LEFT = 1
	};
	class SpriteFont
	{
	private:
		std::map<char, std::string> glyphs;
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
		const tggd::graphics::Sprite& GetGlyphSprite(char) const;
		void WriteTextCentered(SDL_Renderer*, const tggd::graphics::XY<int>&, const std::string&, const std::string&) const;
		tggd::graphics::XY<int> WriteTextLeft(SDL_Renderer*, const tggd::graphics::XY<int>&, const std::string&, const std::string&) const;
		void WriteTextRight(SDL_Renderer*, const tggd::graphics::XY<int>&, const std::string&, const std::string&) const;
		tggd::graphics::XY<int> WriteGlyph(SDL_Renderer*, const tggd::graphics::XY<int>&, char, const std::string&) const;
	public:
		SpriteFont
		(
			const SpriteManager&, 
			const ColorManager&,
			const std::string&
		);
		void WriteText(SDL_Renderer*, const tggd::graphics::XY<int>&, const std::string&, const std::string&, const HorizontalAlignment&) const;
	};
}

