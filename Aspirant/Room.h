#pragma once
#include <vector>
#include "RoomCell.h"
namespace tggd::common
{
	template<typename TObjectData, typename TCellFlags>
	class Room
	{
	private:
		size_t columns;
		size_t rows;
		std::vector<RoomCell<TObjectData, TCellFlags>*> cells;
	public:
		Room(size_t columns, size_t rows)
			: columns(columns)
			, rows(rows)
			, cells()
		{
			for (size_t row = 0; row < rows; ++row)
			{
				for (size_t column = 0; column < columns; ++column)
				{
					cells.push_back(new RoomCell<TObjectData, TCellFlags>(column, row));
				}
			}
		}

		~Room()
		{
			for (auto& item : cells)
			{
				if (item)
				{
					tggd::common::Utility::SafeDelete(item);
				}
			}
		}
		const RoomCell<TObjectData, TCellFlags>* GetCell(size_t column, size_t row) const
		{
			if (column < columns && row < rows)
			{
				return cells[column + row * columns];
			}
			return nullptr;
		}
		RoomCell<TObjectData, TCellFlags>* GetCell(size_t column, size_t row)
		{
			if (column < columns && row < rows)
			{
				return cells[column + row * columns];
			}
			return nullptr;
		}
		size_t GetColumns() const { return columns; }
		size_t GetRows() const { return rows; }
	};
}