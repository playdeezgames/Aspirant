#pragma once
#include "SpriteFont.h"
#include <vector>
namespace graphics::Fonts
{
	void Start(const std::string&);
	const tggd::graphics::SpriteFont& Get(const std::string&);
	const std::vector<std::string>& GetIdentifiers();
}
