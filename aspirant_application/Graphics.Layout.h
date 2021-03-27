#pragma once
#include "json.hpp"
#include <SDL.h>
namespace graphics::Layout
{
	void Draw(SDL_Renderer*, const nlohmann::json&);
}
