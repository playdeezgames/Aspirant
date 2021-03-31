#include "MazeCell.h"
namespace maze
{
	MazeCell::MazeCell()
		: exits()
		, neighbors()
	{

	}

	void MazeCell::SetNeighbor(Direction direction, MazeCell* cell)
	{
		neighbors[direction] = cell;
	}

	void MazeCell::SetDoor(Direction direction, Door* door)
	{
		exits[direction] = door;
	}

	const MazeCell* MazeCell::GetNeighbor(Direction direction) const
	{

		auto neighbor = neighbors.find(direction);
		return neighbor->second;
	}

	MazeCell* MazeCell::GetNeighbor(Direction direction)
	{
		return neighbors[direction];
	}

	const Door* MazeCell::GetDoor(Direction direction) const
	{
		auto door = exits.find(direction);
		return door->second;
	}

	Door* MazeCell::GetDoor(Direction direction)
	{
		return exits[direction];
	}

	bool MazeCell::HasDoor(Direction direction) const
	{
		return exits.find(direction) != exits.end();
	}

	bool MazeCell::HasNeighbor(Direction direction) const
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