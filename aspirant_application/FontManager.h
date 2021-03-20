#pragma once
#include "SpriteFont.h"
#include <vector>
namespace tggd::graphics::FontManager
{
	void Start(const std::string&);
	const SpriteFont& Get(const std::string&);
	const std::vector<std::string>& GetIdentifiers();
}
