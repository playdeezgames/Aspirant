#pragma once
#include <vector>
#include <string>
#include "Scenario.h"
namespace aspirant::editor::context
{
	class EditorRoomListContext
	{
	private:
		aspirant::game::Scenario& scenario;
		std::vector<std::string> roomList;
		size_t roomIndex;
	public:
		EditorRoomListContext(aspirant::game::Scenario&);
		void UpdateRoomList();
		void SetRoomIndex(size_t);
		size_t GetRoomIndex() const;
		const std::vector<std::string>& GetRoomList() const;
		size_t GetRoomCount() const;
		void NextRoom();
		void PreviousRoom();

		const aspirant::game::ScenarioRoom* GetRoom() const;
		aspirant::game::ScenarioRoom* GetRoom();
	};
}