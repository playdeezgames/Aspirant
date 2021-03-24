#include "Context.Editor.Rooms.h"
#include "Common.Utility.h"
#include "Context.Editor.Scenario.h"
#include <vector>
#include <string>
namespace context::editor::Rooms
{
	static std::vector<std::string> roomList;
	static size_t roomIndex = 0;

	void UpdateRoomList()
	{
		roomList = ::context::editor::Scenario::Get().GetRoomKeys();
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

	::game::Room* GetRoom()
	{
		if (GetRoomCount() > GetRoomIndex())
		{
			return ::context::editor::Scenario::Get().GetRoom(GetRoomList()[GetRoomIndex()]);
		}
		else
		{
			return nullptr;
		}
	}
}