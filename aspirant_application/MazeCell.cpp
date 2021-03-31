#include "MazeCell.h"
namespace maze
{
	MazeCell::MazeCell()
		: exits()
		, neighbors()
	{

	}

	void MazeCell::SetNeighbor(MazeDirection direction, MazeCell* cell)
	{
		neighbors[direction] = cell;
	}

	void MazeCell::SetDoor(MazeDirection direction, Door* door)
	{
		exits[direction] = door;
	}

	const MazeCell* MazeCell::GetNeighbor(MazeDirection direction) const
	{

		auto neighbor = neighbors.find(direction);
		return neighbor->second;
	}

	MazeCell* MazeCell::GetNeighbor(MazeDirection direction)
	{
		return neighbors[direction];
	}

	const Door* MazeCell::GetDoor(MazeDirection direction) const
	{
		auto door = exits.find(direction);
		return door->second;
	}

	Door* MazeCell::GetDoor(MazeDirection direction)
	{
		return exits[direction];
	}

	bool MazeCell::HasDoor(MazeDirection direction) const
	{
		return exits.find(direction) != exits.end();
	}

	bool MazeCell::HasNeighbor(MazeDirection direction) const
	{
		return neighbors.find(direction) != neighbors.end();
	}

	bool MazeCell::IsDeadEnd() const
	{
		int count = 0;
		for (auto& entry : exits)
		{
			if (*entry.second == Door::OPEN)
			{
				count++;
			}
		}
		return count == 1;
	}

}