#include "Game.Room.h"
namespace game
{
	void Room::SetSize(size_t columns, size_t rows)
	{
		while (model.size() > rows)
		{
			model.erase(model.size()-1);
		}
		while (model.size() < rows)
		{
			model.push_back(nlohmann::json());
		}

		for (auto& row : model)
		{
			while (row.size() > columns)
			{
				row.erase(row.size() - 1);
			}
			while (row.size() < columns)
			{
				row.push_back(nlohmann::json());
			}
		}
	}

	Room::Room(nlohmann::json& model)
		: model(model)
	{

	}

	Cell Room::GetCell(size_t column, size_t row)
	{
		return Cell(model[row][column], column, row);
	}

	size_t Room::GetColumns() const
	{
		if (model.empty())
		{
			return 0;
		}
		else
		{
			return model.front().size();
		}
	}

	size_t Room::GetRows() const
	{
		return model.size();
	}

}