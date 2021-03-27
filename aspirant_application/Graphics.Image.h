#pragma once
#include "json.hpp"
#include <SDL.h>
namespace graphics::Image
{
	void Draw(SDL_Renderer*, const nlohmann::json&);
}
