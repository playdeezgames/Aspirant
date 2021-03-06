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

	nlohmann::json ScenarioRoom::ToJSON() const
	{
		nlohmann::json properties = nlohmann::json(nlohmann::detail::value_t::array);
		for (size_t row = 0; row < GetRows(); ++row)
		{
			nlohmann::json rowProperties = nlohmann::json(nlohmann::detail::value_t::array);
			for (size_t column = 0; column < GetColumns(); ++column)
			{
				rowProperties.push_back(GetCell(column, row)->ToJSON());
			}
			properties.push_back(rowProperties);
		}
		return properties;
	}


}