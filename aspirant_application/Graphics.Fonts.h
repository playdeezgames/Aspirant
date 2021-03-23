#pragma once
#include "Graphics.Font.h"
#include <vector>
namespace graphics::Fonts
{
	void Start(const std::string&);
	const graphics::Font& Get(const std::string&);
	const std::vector<std::string>& GetIdentifiers();
}
