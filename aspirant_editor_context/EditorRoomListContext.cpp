#include "EditorRoomListContext.h"
#include "Utility.h"
namespace aspirant::editor::context
{
	EditorRoomListContext::EditorRoomListContext(const aspirant::game::Scenario& scenario)
		: scenario(scenario)
	{

	}


	void EditorRoomListContext::UpdateRoomList()
	{
		roomList = scenario.GetRoomKeys();
		if (roomIndex >= roomList.size())
		{
			roomIndex = 0;
		}
	}

	void EditorRoomListContext::SetRoomIndex(size_t index)
	{
		roomIndex = index;
	}

	size_t EditorRoomListContext::GetRoomIndex() const
	{
		return roomIndex;
	}

	const std::vector<std::string>& EditorRoomListContext::GetRoomList() const
	{
		return roomList;
	}

	size_t EditorRoomListContext::GetRoomCount() const
	{
		return roomList.size();
	}

	void EditorRoomListContext::NextRoom()
	{
		SetRoomIndex(tggd::common::Utility::NextIndex(GetRoomIndex(), GetRoomCount()));
	}

	void EditorRoomListContext::PreviousRoom()
	{
		SetRoomIndex(tggd::common::Utility::PreviousIndex(GetRoomIndex(), GetRoomCount()));
	}

}