#include "ScenarioRoom.h"
namespace aspirant
{
	void ScenarioRoom::FromJSON(const nlohmann::json& properties)
	{
		size_t row = 0;
		for (auto& rowProperties : properties)
		{
			size_t column = 0;
			for (auto& cellProperties : rowProperties)
			{
				GetCell(column, row)->FromJSON(cellProperties);
				column++;
			}
			row++;
		}
	}

	ScenarioRoomCell* ScenarioRoom::GenerateRoomCell(size_t column, size_t row)
	{
		return new ScenarioRoomCell(column, row, descriptors);
	}

}