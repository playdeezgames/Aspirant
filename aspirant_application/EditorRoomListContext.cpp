#include "EditorRoomListContext.h"
#include "Common.Utility.h"
#include "EditorContext.h"
#include <vector>
#include <string>
namespace aspirant::editor::context::EditorRoomListContext
{
	static std::vector<std::string> roomList;
	static size_t roomIndex = 0;

	void UpdateRoomList()
	{
		roomList = EditorContext::GetScenario().GetRoomKeys();
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
			return EditorContext::GetScenario().GetRoom(GetRoomList()[GetRoomIndex()]);
		}
		else
		{
			return nullptr;
		}
	}
}