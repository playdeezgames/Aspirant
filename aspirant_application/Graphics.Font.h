#pragma once
#include "Graphics.Sprite.h"
#include <string>
#include <map>
#include "Common.XY.h"
namespace graphics
{
	enum class HorizontalAlignment
	{
		RIGHT = -1,
		CENTER = 0,
		LEFT = 1
	};
	class Font
	{
		Font() = delete;
		Font(const Font&) = delete;
		Font(Font&&) = delete;
		Font& operator=(const Font&) = delete;
		Font& operator=(Font&&) = delete;
	private:
		std::map<char, std::string> glyphs;
		const graphics::Sprite& GetGlyphSprite(char) const;
		void WriteTextCentered(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&) const;
		common::XY<int> WriteTextLeft(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&) const;
		void WriteTextRight(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&) const;
		common::XY<int> WriteGlyph(SDL_Renderer*, const common::XY<int>&, char, const std::string&) const;
	public:
		Font
		(
			const std::string&
		);
		void WriteText(SDL_Renderer*, const common::XY<int>&, const std::string&, const std::string&, const HorizontalAlignment&) const;
	};
}

