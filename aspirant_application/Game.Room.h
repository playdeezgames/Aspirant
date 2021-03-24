#pragma once
#include "Game.Cell.h"
namespace game
{
	class Room
	{
	private:
		size_t columns;
		size_t rows;
		std::vector<Cell*> cells;
		void Clear()
		{
			for (auto& item : cells)
			{
				if (item)
				{
					common::Finisher::Finish(item);
				}
			}
			cells.clear();
			columns = 0;
			rows = 0;
		}
	public:
		void SetSize(size_t columnCount, size_t rowCount)
		{
			Clear();
			columns = columnCount;
			rows = rowCount;
			for (size_t row = 0; row < rows; ++row)
			{
				for (size_t column = 0; column < columns; ++column)
				{
					cells.push_back(new Cell(column, row));
				}
			}
		}
		Room()
			: columns(0)
			, rows(0)
			, cells()
		{

		}
		~Room()
		{
			Clear();
		}
		const Cell* GetCell(size_t column, size_t row) const
		{
			if (column < columns && row < rows)
			{
				return cells[column + row * columns];
			}
			return nullptr;
		}
		Cell* GetCell(size_t column, size_t row)
		{
			if (column < columns && row < rows)
			{
				return cells[column + row * columns];
			}
			return nullptr;
		}
		size_t GetColumns() const { return columns; }
		size_t GetRows() const { return rows; }
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
