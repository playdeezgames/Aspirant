#pragma once
#include "Scenario.h"
#include "DescriptorManager.h"
#include "ScenarioDescriptorManager.h"
#include <vector>
#include "EditorScenarioSelector.h"
#include "EditorNewRoomContext.h"
#include "EditorRoomListContext.h"
namespace aspirant::editorui
{
	class EditorContext
	{
	private:
		EditorScenarioSelector scenarioSelector;
		EditorNewRoomContext newRoom;
		EditorRoomListContext roomList;
		aspirant::game::Scenario scenario;
	public:
		EditorContext(const aspirant::game::DescriptorManager&, aspirant::game::ScenarioDescriptorManager&);

		const EditorScenarioSelector& GetScenarioSelector() const
		{
			return scenarioSelector;
		}
		EditorScenarioSelector& GetScenarioSelector()
		{
			return scenarioSelector;
		}
		const EditorNewRoomContext& GetNewRoom() const
		{
			return newRoom;
		}
		EditorNewRoomContext& GetNewRoom()
		{
			return newRoom;
		}
		const EditorRoomListContext& GetRoomList() const
		{
			return roomList;
		}
		EditorRoomListContext& GetRoomList()
		{
			return roomList;
		}


		const aspirant::game::Scenario& GetScenario() const { return scenario; }
		aspirant::game::Scenario& GetScenario() { return scenario; }
		void SaveScenario();

	};
}
