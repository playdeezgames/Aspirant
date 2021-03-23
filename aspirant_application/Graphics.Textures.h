#pragma once
#include <SDL.h>
#include <map>
#include <string>
#include "Common.Finishers.h"
namespace graphics::Textures
{
	void Start(SDL_Renderer*, const std::string&);
	SDL_Texture* Get(const std::string&);
}

