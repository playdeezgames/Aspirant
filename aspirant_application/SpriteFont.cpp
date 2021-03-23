#include "SpriteFont.h"
#include "Utility.h"
#include "Data.JSON.h"
#include "SpriteManager.h"
#include "Graphics.Colors.h"
namespace tggd::graphics
{
	SpriteFont::SpriteFont
	(
		const std::string& fileName
	)
		: glyphs()
	{
		nlohmann::json properties = data::JSON::Load(fileName);
		for (auto& item : properties.items())
		{
			char ch = (char)tggd::common::Utility::StringToInt(item.key());
			glyphs[ch] = item.value();
		}
	}

	const tggd::graphics::Sprite& SpriteFont::GetGlyphSprite(char ch) const
	{
		auto iter = glyphs.find(ch);
		return SpriteManager::Get(iter->second);
	}

	tggd::common::XY<int> SpriteFont::WriteGlyph(SDL_Renderer* renderer, const tggd::common::XY<int>& xy, char ch, const std::string& color) const
	{
		const auto& sprite = GetGlyphSprite(ch);
		sprite.Draw(renderer, xy, ::graphics::Colors::Get(color));
		return tggd::common::XY(xy.GetX() + sprite.GetWidth(), xy.GetY());
	}

	tggd::common::XY<int> SpriteFont::WriteTextLeft(SDL_Renderer* renderer, const tggd::common::XY<int>& xy, const std::string& text, const std::string& color) const
	{
		tggd::common::XY<int> temp = xy;
		for (auto ch : text)
		{
			temp = WriteGlyph(renderer, temp, ch, color);
		}
		return temp;
	}

	void SpriteFont::WriteTextCentered(SDL_Renderer* renderer, const tggd::common::XY<int>& xy, const std::string& text, const std::string& color) const
	{
		int width = 0;
		for (auto ch : text)
		{
			const auto& sprite = GetGlyphSprite(ch);
			width += sprite.GetWidth();
		}
		auto adjustedXY = tggd::common::XY<int>(xy.GetX() - width / 2, xy.GetY());
		WriteTextLeft(renderer, adjustedXY, text, color);
	}

	void SpriteFont::WriteTextRight(SDL_Renderer* renderer, const tggd::common::XY<int>& xy, const std::string& text, const std::string& color) const
	{
		int width = 0;
		for (auto ch : text)
		{
			const auto& sprite = GetGlyphSprite(ch);
			width += sprite.GetWidth();
		}
		auto adjustedXY = tggd::common::XY<int>(xy.GetX() - width, xy.GetY());
		WriteTextLeft(renderer, adjustedXY, text, color);
	}

	void SpriteFont::WriteText
	(
		SDL_Renderer* renderer,
		const tggd::common::XY<int>& xy,
		const std::string& text,
		const std::string& color,
		const HorizontalAlignment& alignment
	) const
	{
		switch (alignment)
		{
		case HorizontalAlignment::LEFT:
			WriteTextLeft(renderer, xy, text, color);
			break;
		case HorizontalAlignment::RIGHT:
			WriteTextRight(renderer, xy, text, color);
			break;
		case HorizontalAlignment::CENTER:
			WriteTextCentered(renderer, xy, text, color);
			break;
		}
	}

}
