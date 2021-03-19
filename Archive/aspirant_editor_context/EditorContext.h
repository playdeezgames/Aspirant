#pragma once
#include "Scenario.h"
#include "DescriptorManager.h"
#include "ScenarioDescriptorManager.h"
#include <vector>
#include "EditorScenarioSelector.h"
#include "EditorNewRoomContext.h"
#include "EditorRoomListContext.h"
#include "EditorRoomViewContext.h"
#include "EditorRoomCellObjectsContext.h"
#include "EditorDescriptorSelectorContext.h"
namespace aspirant::editor::context
{
	class EditorContext
	{
		EditorContext() = delete;
		EditorContext(const EditorContext&) = delete;
		EditorContext(EditorContext&&) = delete;
		EditorContext& operator=(const EditorContext&) = delete;
		EditorContext& operator=(EditorContext&&) = delete;
	private:
		EditorScenarioSelector scenarioSelector;
		EditorNewRoomContext newRoom;
		EditorRoomListContext roomList;
		EditorRoomViewContext roomView;
		EditorRoomCellObjectsContext roomCellObjects;
		EditorDescriptorSelectorContext descriptorSelector;
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

		const EditorRoomViewContext& GetRoomView() const
		{
			return roomView;
		}
		EditorRoomViewContext& GetRoomView()
		{
			return roomView;
		}

		const EditorRoomCellObjectsContext& GetRoomCellObjects() const
		{
			return roomCellObjects;
		}
		EditorRoomCellObjectsContext& GetRoomCellObjects()
		{
			return roomCellObjects;
		}
		const EditorDescriptorSelectorContext& GetDescriptorSelector() const
		{
			return descriptorSelector;
		}
		EditorDescriptorSelectorContext& GetDescriptorSelector()
		{
			return descriptorSelector;
		}

		const aspirant::game::Scenario& GetScenario() const { return scenario; }
		aspirant::game::Scenario& GetScenario() { return scenario; }
		void SaveScenario();

	};
}