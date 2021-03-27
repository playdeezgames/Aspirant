#pragma once
#include "json.hpp"
#include <SDL.h>
namespace graphics::Text
{
	void Draw(SDL_Renderer*, const nlohmann::json&);
}
