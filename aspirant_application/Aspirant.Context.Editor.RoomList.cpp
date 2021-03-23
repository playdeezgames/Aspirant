#include "Aspirant.Context.Editor.RoomList.h"
#include "Common.Utility.h"
#include "Aspirant.Context.Editor.Scenario.h"
#include <vector>
#include <string>
namespace aspirant::context::editor::RoomList
{
	static std::vector<std::string> roomList;
	static size_t roomIndex = 0;

	void UpdateRoomList()
	{
		roomList = aspirant::context::editor::Scenario::Get().GetRoomKeys();
		if (roomIndex >= roomList.size())
		{
			roomIndex = 0;
		}
	}

	void SetRoomIndex(size_t index)
	{
		roomIndex = index;
	}

	size_t GetRoomIndex()
	{
		return roomIndex;
	}

	const std::vector<std::string>& GetRoomList()
	{
		return roomList;
	}

	size_t GetRoomCount()
	{
		return roomList.size();
	}

	void NextRoom()
	{
		SetRoomIndex(common::Utility::NextIndex(GetRoomIndex(), GetRoomCount()));
	}

	void PreviousRoom()
	{
		SetRoomIndex(common::Utility::PreviousIndex(GetRoomIndex(), GetRoomCount()));
	}

	aspirant::game::ScenarioRoom* GetRoom()
	{
		if (GetRoomCount() > GetRoomIndex())
		{
			return aspirant::context::editor::Scenario::Get().GetRoom(GetRoomList()[GetRoomIndex()]);
		}
		else
		{
			return nullptr;
		}
	}
}