#include "Aspirant.Context.Editor.NewRoom.h"
#include "Game.Descriptors.h"
#include <vector>
#include "Common.Finisher.h"
#include "Game.Object.Common.h"
namespace aspirant::context::editor::NewRoom
{
	const std::string DEFAULT_ROOM_NAME = "<replace me>";
	const size_t DEFAULT_ROOM_COLUMNS = 10;
	const size_t DEFAULT_ROOM_ROWS = 10;
	const size_t MINIMUM_COLUMNS = 1;
	const size_t MINIMUM_ROWS = 1;
	const size_t DELTA_COLUMNS = 1;
	const size_t DELTA_ROWS = 1;

	static std::string newRoomName = "";
	static size_t newRoomColumns = 0;
	static size_t newRoomRows = 0;
	static std::vector<std::string> terrains;
	static size_t terrainIndex;

	void Reset()
	{
		newRoomName = DEFAULT_ROOM_NAME;
		newRoomColumns = DEFAULT_ROOM_COLUMNS;
		newRoomRows = DEFAULT_ROOM_ROWS;
	}

	const std::string& GetName()
	{
		return newRoomName;
	}

	void AppendName(const std::string& text)
	{
		if (text == "\b")
		{
			if (!newRoomName.empty())
			{
				newRoomName.pop_back();
			}
		}
		else
		{
			newRoomName += text;
		}
	}

	void ClearName()
	{
		newRoomName = "";
	}

	size_t GetColumns()
	{
		return newRoomColumns;
	}

	void IncrementColumns()
	{
		newRoomColumns+=DELTA_COLUMNS;
	}

	void DecrementColumns()
	{
		newRoomColumns = (newRoomColumns <= MINIMUM_COLUMNS) ? (MINIMUM_COLUMNS) : (newRoomColumns - DELTA_COLUMNS);
	}

	size_t GetRows()
	{
		return newRoomRows;
	}

	void IncrementRows()
	{
		newRoomRows+=DELTA_ROWS;
	}

	void DecrementRows()
	{
		newRoomRows = (newRoomRows <= MINIMUM_ROWS) ? (MINIMUM_ROWS) : (newRoomRows - DELTA_ROWS);
	}

	void Start()
	{
		terrains.clear();
		auto identifiers = game::Descriptors::GetIdentifiers();
		for (auto& identifier : identifiers)
		{
			auto descriptor = game::Descriptors::Get(identifier);
			auto obj = descriptor->CreateObject();
			if (obj->CanCover(nullptr))
			{
				terrains.push_back(identifier);
			}
			common::Finisher::Finish(obj);
		}
	}

	const std::string GetTerrain()
	{
		return terrains[terrainIndex];
	}

	void NextTerrain()
	{
		terrainIndex = (terrainIndex + 1) % terrains.size();
	}

	void PreviousTerrain()
	{
		terrainIndex = (terrainIndex + terrains.size() - 1) % terrains.size();
	}
}
