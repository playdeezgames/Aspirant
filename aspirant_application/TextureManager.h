#pragma once
#include <SDL.h>
#include <map>
#include <string>
#include "FinishManager.h"
namespace tggd::graphics::TextureManager
{
	void Start(SDL_Renderer*, const std::string&);
	SDL_Texture* Get(const std::string&);
}

