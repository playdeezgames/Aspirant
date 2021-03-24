#pragma once
#include "Game.Cell.h"
namespace context::editor::Cell
{
	size_t GetIndex();
	game::Cell* GetCell();
	void Reset();
}