#pragma once
#include "Maze.Direction.h"
#include "Maze.Door.h"
#include <map>
#include <vector>
namespace maze
{
	class MazeCell
	{
	private:
		std::map<Direction, Door*> exits;
		std::map<Direction, MazeCell*> neighbors;
	public:
		MazeCell();
		void SetNeighbor(Direction, MazeCell*);
		void SetDoor(Direction, Door*);
		const MazeCell* GetNeighbor(Direction) const;
		MazeCell* GetNeighbor(Direction);
		const Door* GetDoor(Direction) const;
		Door* GetDoor(Direction);
		bool HasDoor(Direction) const;
		bool HasNeighbor(Direction) const;
		bool IsDeadEnd() const;
	};
}