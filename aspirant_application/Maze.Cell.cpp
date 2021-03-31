#include "Maze.Cell.h"
namespace maze
{
	Cell::Cell()
		: exits()
		, neighbors()
	{

	}

	void Cell::SetNeighbor(Direction direction, Cell* cell)
	{
		neighbors[direction] = cell;
	}

	void Cell::SetDoor(Direction direction, Door* door)
	{
		exits[direction] = door;
	}

	const Cell* Cell::GetNeighbor(Direction direction) const
	{

		auto neighbor = neighbors.find(direction);
		return neighbor->second;
	}

	Cell* Cell::GetNeighbor(Direction direction)
	{
		return neighbors[direction];
	}

	const Door* Cell::GetDoor(Direction direction) const
	{
		auto door = exits.find(direction);
		return door->second;
	}

	Door* Cell::GetDoor(Direction direction)
	{
		return exits[direction];
	}

	bool Cell::HasDoor(Direction direction) const
	{
		return exits.find(direction) != exits.end();
	}

	bool Cell::HasNeighbor(Direction direction) const
	{
		return neighbors.find(direction) != neighbors.end();
	}

	bool Cell::IsDeadEnd() const
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