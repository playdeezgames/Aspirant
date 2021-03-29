#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Game.ScenarioDescriptors.h"
#include "Context.Editor.Scenarios.h"
#include <sstream>
#include "Context.Editor.Rooms.h"
#include "Context.Editor.NewRoom.h"
namespace state::editor::Scenario
{
	const std::string LAYOUT_NAME = "State.Editor.Scenario";
	const std::string MENU_ID = "Scenario";
	const std::string HEADER_TEXT_ID = "Header";

	enum class EditScenarioItem
	{
		DESCRIPTOR,
		AVATAR,
		OPEN_ROOM,
		NEW_ROOM,
		BACK
	};

	static void ActivateItem()
	{
		switch ((EditScenarioItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME, MENU_ID).value())
		{
		case EditScenarioItem::BACK:
			::Application::SetUIState(::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		case EditScenarioItem::DESCRIPTOR:
			::Application::SetUIState(::UIState::EDIT_SCENARIO_DESCRIPTOR);
			break;
		case EditScenarioItem::AVATAR:
			::Application::SetUIState(::UIState::EDIT_AVATAR);
			break;
		case EditScenarioItem::OPEN_ROOM:
			::context::editor::Rooms::UpdateRoomList();
			::Application::SetUIState(::UIState::EDIT_PICK_ROOM);
			break;
		case EditScenarioItem::NEW_ROOM:
			::context::editor::NewRoom::Reset();
			::Application::SetUIState(::UIState::EDIT_NEW_ROOM);
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		}
	}

	static void UpdateHeader(const Uint32&)
	{
		std::stringstream ss;
		auto scenario = ::game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex());
		ss << scenario.GetName() << "(id=" << scenario.GetId() << ")";//TODO: magic strings
		graphics::Layouts::SetTextText(LAYOUT_NAME, HEADER_TEXT_ID, ss.str());
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_SCENARIO, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_SCENARIO, LAYOUT_NAME);
		::Application::AddUpdateHandler(::UIState::EDIT_SCENARIO, UpdateHeader);
	}
}
