#pragma once
#include <string>
#include <SDL.h>
#include <vector>
namespace graphics::Colors
{
	void Start(const std::string&);
	const SDL_Color& Get(const std::string&);
	const std::vector<std::string>& GetIdentifiers();
}