#include "MazeRenderer.h"
#include "Maze.h"
namespace maze::Renderer
{
	static maze::Maze maze(7, 8);
	const int CELL_WIDTH = 16;
	const int CELL_HEIGHT = 16;

	void Render(SDL_Renderer* renderer)
	{
		SDL_SetRenderDrawColor(renderer, 0x80, 0x00, 0x80, 0xff);
		auto& directions = maze::MazeDirectionHelper::GetAll();
		for (auto row = 0; row < maze.GetRows(); ++row)
		{
			for (auto column = 0; column < maze.GetColumns(); ++column)
			{
				int x = column * CELL_WIDTH + CELL_WIDTH / 2;
				int y = row * CELL_HEIGHT + CELL_HEIGHT / 2;
				auto cell = maze.GetCell(column, row);
				if (cell)
				{
					for (auto direction : directions)
					{
						int nextX =
							(direction == maze::Direction::EAST) ? (x + CELL_WIDTH) :
							(direction == maze::Direction::WEST) ? (x - CELL_WIDTH) :
							(x);
						int nextY =
							(direction == maze::Direction::SOUTH) ? (y + CELL_HEIGHT) :
							(direction == maze::Direction::NORTH) ? (y - CELL_HEIGHT) :
							(y);
						auto door = cell->GetDoor(direction);
						if (door && *(door.value()) == Door::OPEN)
						{
							SDL_RenderDrawLine(renderer, x, y, nextX, nextY);
						}
					}
				}
			}
		}
	}

	void Start()
	{
		maze.Generate();
	}
}
