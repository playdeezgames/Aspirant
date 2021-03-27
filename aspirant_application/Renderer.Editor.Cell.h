#pragma once
#include <SDL.h>
#include "json.hpp"
namespace renderer::editor::RoomCellObjects
{
	void Draw(SDL_Renderer*, const nlohmann::json&);
}