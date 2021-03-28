#include "Graphics.Font.h"
#include "Common.Utility.h"
#include "Data.JSON.h"
#include "Graphics.Sprites.h"
#include "Graphics.Colors.h"
namespace graphics
{
	Font::Font
	(
		const std::string& fileName
	)
		: glyphs()
	{
		nlohmann::json properties = data::JSON::Load(fileName);
		for (auto& item : properties.items())
		{
			char ch = (char)::common::Utility::StringToInt(item.key());
			glyphs[ch] = item.value();
		}
	}

	std::optional<graphics::Sprite> Font::GetGlyphSprite(char ch) const
	{
		auto iter = glyphs.find(ch);
		return Sprites::Read(iter->second);
	}

	common::XY<int> Font::WriteGlyph(SDL_Renderer* renderer, const common::XY<int>& xy, char ch, const std::string& color) const
	{
		const auto& sprite = GetGlyphSprite(ch);
		sprite.value().Draw(renderer, xy, ::graphics::Colors::Get(color));
		return common::XY(xy.GetX() + sprite.value().GetWidth(), xy.GetY());
	}

	common::XY<int> Font::WriteTextLeft(SDL_Renderer* renderer, const common::XY<int>& xy, const std::string& text, const std::string& color) const
	{
		common::XY<int> temp = xy;
		for (auto ch : text)
		{
			temp = WriteGlyph(renderer, temp, ch, color);
		}
		return temp;
	}

	void Font::WriteTextCentered(SDL_Renderer* renderer, const common::XY<int>& xy, const std::string& text, const std::string& color) const
	{
		int width = 0;
		for (auto ch : text)
		{
			const auto& sprite = GetGlyphSprite(ch);
			width += sprite.value().GetWidth();
		}
		auto adjustedXY = common::XY<int>(xy.GetX() - width / 2, xy.GetY());
		WriteTextLeft(renderer, adjustedXY, text, color);
	}

	void Font::WriteTextRight(SDL_Renderer* renderer, const common::XY<int>& xy, const std::string& text, const std::string& color) const
	{
		int width = 0;
		for (auto ch : text)
		{
			const auto& sprite = GetGlyphSprite(ch);
			width += sprite.value().GetWidth();
		}
		auto adjustedXY = common::XY<int>(xy.GetX() - width, xy.GetY());
		WriteTextLeft(renderer, adjustedXY, text, color);
	}

	void Font::WriteText
	(
		SDL_Renderer* renderer,
		const common::XY<int>& xy,
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
