#include "State.Editor.Scenario.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Game.ScenarioDescriptors.h"
#include "Context.Editor.Scenarios.h"
#include "Data.Strings.h"
#include <sstream>
#include "MenuItem.h"
#include "Context.Editor.Rooms.h"
#include "Context.Editor.NewRoom.h"
namespace state::editor::Scenario
{
	const std::string LAYOUT_NAME = "EditScenario";
	const std::string ITEM_DESCRIPTOR_COLOR_NAME = "EditScenario.Color.Descriptor";
	const std::string ITEM_OPEN_ROOM_COLOR_NAME = "EditScenario.Color.OpenRoom";
	const std::string ITEM_NEW_ROOM_COLOR_NAME = "EditScenario.Color.NewRoom";
	const std::string ITEM_BACK_COLOR_NAME = "EditScenario.Color.Back";
	const std::string HEADER_TEXT_NAME = "EditScenario.Text.Header";

	enum class EditScenarioItem
	{
		DESCRIPTOR,
		OPEN_ROOM,
		NEW_ROOM,
		BACK
	};
	static EditScenarioItem current = EditScenarioItem::BACK;
	static std::map<EditScenarioItem, ::MenuItem<EditScenarioItem>> items =
	{
		{EditScenarioItem::DESCRIPTOR, ::MenuItem<EditScenarioItem>(ITEM_DESCRIPTOR_COLOR_NAME, EditScenarioItem::BACK, EditScenarioItem::OPEN_ROOM)},
		{EditScenarioItem::OPEN_ROOM, ::MenuItem<EditScenarioItem>(ITEM_OPEN_ROOM_COLOR_NAME, EditScenarioItem::DESCRIPTOR, EditScenarioItem::NEW_ROOM)},
		{EditScenarioItem::NEW_ROOM, ::MenuItem<EditScenarioItem>(ITEM_NEW_ROOM_COLOR_NAME, EditScenarioItem::OPEN_ROOM, EditScenarioItem::BACK)},
		{EditScenarioItem::BACK, ::MenuItem<EditScenarioItem>(ITEM_BACK_COLOR_NAME, EditScenarioItem::NEW_ROOM, EditScenarioItem::DESCRIPTOR)}
	};

	static void ActivateItem()
	{
		switch (current)
		{
		case EditScenarioItem::BACK:
			::Application::SetUIState(::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		case EditScenarioItem::DESCRIPTOR:
			::Application::SetUIState(::UIState::EDIT_SCENARIO_DESCRIPTOR);
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
			MenuItem<EditScenarioItem>::Previous(current, items);
			break;
		case ::Command::DOWN:
			MenuItem<EditScenarioItem>::Next(current, items);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void UpdateHeader()
	{
		std::stringstream ss;
		auto scenario = ::game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex());
		ss << scenario->GetName() << "(id=" << scenario->GetId() << ")";//TODO: magic strings
		::data::Strings::Set(HEADER_TEXT_NAME, ss.str());
	}

	static void OnUpdate(const Uint32& ticks)
	{
		UpdateHeader();
		MenuItem<EditScenarioItem>::Update(items, current);
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_SCENARIO, OnCommand);
		::Application::SetRenderHandler(::UIState::EDIT_SCENARIO, OnDraw);
		::Application::SetUpdateHandler(::UIState::EDIT_SCENARIO, OnUpdate);
	}
}
