#pragma once
#include <vector>
#include "RoomCell.h"
#include "json.hpp"
namespace tggd::common
{
	template<typename TRoomCell>
	class Room
	{
	private:
		size_t columns;
		size_t rows;
		std::vector<TRoomCell*> cells;
	protected:
		virtual TRoomCell* GenerateRoomCell(size_t, size_t) = 0;
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
					cells.push_back(GenerateRoomCell(column, row));
				}
			}
		}
		virtual void FromJSON(const nlohmann::json&) = 0;
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
		const TRoomCell* GetCell(size_t column, size_t row) const
		{
			if (column < columns && row < rows)
			{
				return cells[column + row * columns];
			}
			return nullptr;
		}
		TRoomCell* GetCell(size_t column, size_t row)
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