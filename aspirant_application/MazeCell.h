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
		std::map<MazeDirection, Door*> exits;
		std::map<MazeDirection, MazeCell*> neighbors;
	public:
		MazeCell();
		void SetNeighbor(MazeDirection, MazeCell*);
		void SetDoor(MazeDirection, Door*);
		const MazeCell* GetNeighbor(MazeDirection) const;
		MazeCell* GetNeighbor(MazeDirection);
		const Door* GetDoor(MazeDirection) const;
		Door* GetDoor(MazeDirection);
		bool HasDoor(MazeDirection) const;
		bool HasNeighbor(MazeDirection) const;
		bool IsDeadEnd() const;
	};
}