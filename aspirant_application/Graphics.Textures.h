#pragma once
#include <SDL.h>
#include <map>
#include <string>
#include "Common.Finishers.h"
namespace graphics::Textures
{
	void InitializeFromFile(SDL_Renderer*, const std::string&);
	SDL_Texture* Read(const std::string&);
}

