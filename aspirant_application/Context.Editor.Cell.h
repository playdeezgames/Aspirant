#pragma once
#include "Game.Cell.h"
namespace context::editor::Cell
{
	size_t GetIndex();
	std::optional<game::Cell> GetCell();
	void Reset();
}