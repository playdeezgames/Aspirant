#pragma once
#include "Sprite.h"
#include <string>
#include <map>
#include "Common.XY.h"
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
		SpriteFont() = delete;
		SpriteFont(const SpriteFont&) = delete;
		SpriteFont(SpriteFont&&) = delete;
		SpriteFont& operator=(const SpriteFont&) = delete;
		SpriteFont& operator=(SpriteFont&&) = delete;
	private:
		std::map<char, std::string> glyphs;
		const tggd::graphics::Sprite& GetGlyphSprite(char) const;
		void WriteTextCentered(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&) const;
		common::XY<int> WriteTextLeft(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&) const;
		void WriteTextRight(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&) const;
		common::XY<int> WriteGlyph(SDL_Renderer*, const common::XY<int>&, char, const std::string&) const;
	public:
		SpriteFont
		(
			const std::string&
		);
		void WriteText(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&, const HorizontalAlignment&) const;
	};
}

