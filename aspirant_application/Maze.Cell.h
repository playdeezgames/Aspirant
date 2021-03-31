#pragma once
#include "Maze.Direction.h"
#include "Maze.Door.h"
#include <map>
#include <vector>
namespace maze
{
	class Cell
	{
	private:
		std::map<Direction, Door*> exits;
		std::map<Direction, Cell*> neighbors;
	public:
		Cell();
		void SetNeighbor(Direction, Cell*);
		void SetDoor(Direction, Door*);
		const Cell* GetNeighbor(Direction) const;
		Cell* GetNeighbor(Direction);
		const Door* GetDoor(Direction) const;
		Door* GetDoor(Direction);
		bool HasDoor(Direction) const;
		bool HasNeighbor(Direction) const;
		bool IsDeadEnd() const;
	};
}