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

	std::optional<const Door*> Cell::GetDoor(Direction direction) const
	{
		auto door = exits.find(direction);
		return 
			(door!=exits.end()) ? 
			(std::optional<const Door*>(door->second)) : 
			(std::nullopt);
	}

	std::optional<Door*> Cell::GetDoor(Direction direction)
	{
		auto door = exits.find(direction);
		return
			(door != exits.end()) ?
			(std::optional<Door*>(door->second)) :
			(std::nullopt);
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