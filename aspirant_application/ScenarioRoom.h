#pragma once
#include "ScenarioRoomCell.h"
namespace aspirant::game
{
	class ScenarioRoom
	{
	private:
		size_t columns;
		size_t rows;
		std::vector<ScenarioRoomCell*> cells;
		void Clear()
		{
			for (auto& item : cells)
			{
				if (item)
				{
					tggd::common::FinishUtility::SafeDelete(item);
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
					cells.push_back(new ScenarioRoomCell(column, row));
				}
			}
		}
		ScenarioRoom()
			: columns(0)
			, rows(0)
			, cells()
		{

		}
		~ScenarioRoom()
		{
			Clear();
		}
		const ScenarioRoomCell* GetCell(size_t column, size_t row) const
		{
			if (column < columns && row < rows)
			{
				return cells[column + row * columns];
			}
			return nullptr;
		}
		ScenarioRoomCell* GetCell(size_t column, size_t row)
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
