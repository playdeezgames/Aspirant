#pragma once
#include "ScenarioObjectInstance.h"
#include "XY.h"
#include <SDL.h>
namespace aspirant::editor::controls::EditorBaseControl
{
	void DrawDescriptor
	(
		SDL_Renderer* renderer,
		tggd::common::XY<int> position,
		const aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>& descriptor
	);
	void DrawObject
	(
		SDL_Renderer* renderer,
		tggd::common::XY<int> position,
		const aspirant::game::ScenarioObjectInstance* obj
	);
}