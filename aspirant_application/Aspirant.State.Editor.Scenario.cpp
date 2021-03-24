#include "Aspirant.State.Editor.Scenario.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
#include "Game.ScenarioDescriptors.h"
#include "Aspirant.Context.Editor.Scenarios.h"
#include "Data.Strings.h"
#include <sstream>
#include "MenuItemDescriptor.h"
#include "Aspirant.Context.Editor.Rooms.h"
#include "Aspirant.Context.Editor.NewRoom.h"
namespace aspirant::state::editor::Scenario
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
	static std::map<EditScenarioItem, aspirant::commonui::MenuItemDescriptor<EditScenarioItem>> items;

	static void ActivateItem()
	{
		switch (current)
		{
		case EditScenarioItem::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		case EditScenarioItem::DESCRIPTOR:
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO_DESCRIPTOR);
			break;
		case EditScenarioItem::OPEN_ROOM:
			aspirant::context::editor::Rooms::UpdateRoomList();
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_PICK_ROOM);
			break;
		case EditScenarioItem::NEW_ROOM:
			aspirant::context::editor::NewRoom::Reset();
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_NEW_ROOM);
			break;
		}
	}

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case aspirant::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case aspirant::Command::GREEN:
			ActivateItem();
			break;
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO_SELECTOR);
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
		auto scenario = ::game::ScenarioDescriptors::Get(aspirant::context::editor::Scenarios::GetIndex());
		ss << scenario->GetName() << "(id=" << scenario->GetId() << ")";//TODO: magic strings
		::data::Strings::Set(HEADER_TEXT_NAME, ss.str());
	}

	static void OnUpdate(const Uint32& ticks)
	{
		UpdateHeader();
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::UIState::EDIT_SCENARIO, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::EDIT_SCENARIO, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::EDIT_SCENARIO, OnUpdate);
		items[EditScenarioItem::DESCRIPTOR]= aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_DESCRIPTOR_COLOR_NAME, EditScenarioItem::BACK, EditScenarioItem::OPEN_ROOM);
		items[EditScenarioItem::OPEN_ROOM]= aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_OPEN_ROOM_COLOR_NAME, EditScenarioItem::DESCRIPTOR, EditScenarioItem::NEW_ROOM);
		items[EditScenarioItem::NEW_ROOM]= aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_NEW_ROOM_COLOR_NAME, EditScenarioItem::OPEN_ROOM, EditScenarioItem::BACK);
		items[EditScenarioItem::BACK]= aspirant::commonui::MenuItemDescriptor<EditScenarioItem>(ITEM_BACK_COLOR_NAME, EditScenarioItem::NEW_ROOM, EditScenarioItem::DESCRIPTOR);
	}
}
