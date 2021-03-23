#pragma once
#include "Game.Object.Common.h"
#include "Common.XY.h"
#include <SDL.h>
namespace renderer::editor::Common
{
	void DrawDescriptor
	(
		SDL_Renderer* renderer,
		common::XY<int> position,
		const ::game::descriptor::Common& descriptor
	);
	void DrawObject
	(
		SDL_Renderer* renderer,
		common::XY<int> position,
		const ::game::object::Common* obj
	);
}