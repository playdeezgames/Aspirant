#pragma once
#include <SDL.h>
#include "json.hpp"
namespace graphics::Menu
{
	void Draw(SDL_Renderer*, const nlohmann::json&);
}