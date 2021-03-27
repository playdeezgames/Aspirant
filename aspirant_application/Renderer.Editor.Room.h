#pragma once
#include <SDL.h>
#include "json.hpp"
namespace renderer::editor::Room
{
	void Draw(SDL_Renderer*, const nlohmann::json&);
}