#include "State.Editor.ScenarioDescriptor.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "MenuItem.h"
#include "Context.Editor.Scenarios.h"
#include "Data.Strings.h"
#include "Game.ScenarioDescriptors.h"
namespace state::editor::ScenarioDescriptor
{
	const std::string LAYOUT_NAME = "EditScenarioDescriptor";
	const std::string COLOR_NAME_SCENARIO_NAME = "EditScenarioDescriptor.Color.ScenarioName";
	const std::string COLOR_NAME_BRIEF = "EditScenarioDescriptor.Color.Brief";
	const std::string COLOR_NAME_BACK = "EditScenarioDescriptor.Color.Back";
	const std::string TEXT_NAME_SCENARIO_NAME = "EditScenarioDescriptor.Text.ScenarioName";
	const std::string TEXT_NAME_BRIEF = "EditScenarioDescriptor.Text.Brief";

	enum class EditScenarioDescriptorItem
	{
		SCENARIO_NAME,
		BRIEF,
		BACK
	};

	static EditScenarioDescriptorItem current = EditScenarioDescriptorItem::BACK;
	static std::map<EditScenarioDescriptorItem, ::MenuItem<EditScenarioDescriptorItem>> items =
	{
		{EditScenarioDescriptorItem::SCENARIO_NAME, ::MenuItem<EditScenarioDescriptorItem>(COLOR_NAME_SCENARIO_NAME, EditScenarioDescriptorItem::BACK, EditScenarioDescriptorItem::BRIEF)},
		{EditScenarioDescriptorItem::BRIEF, ::MenuItem<EditScenarioDescriptorItem>(COLOR_NAME_BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME, EditScenarioDescriptorItem::BACK)},
		{EditScenarioDescriptorItem::BACK, ::MenuItem<EditScenarioDescriptorItem>(COLOR_NAME_BACK, EditScenarioDescriptorItem::BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME)}
	};

	void ActivateItem()
	{
		switch (current)
		{
		case EditScenarioDescriptorItem::BACK:
			::Application::SetUIState(::UIState::EDIT_SCENARIO);
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		auto descriptor = ::game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex());
		std::string temp;
		switch (command)
		{
		case ::Command::BACK:
			switch (current)
			{
			case EditScenarioDescriptorItem::SCENARIO_NAME:
				temp = descriptor->GetName();
				if (!temp.empty())
				{
					temp.pop_back();
				}
				descriptor->SetName(temp);
				break;
			case EditScenarioDescriptorItem::BRIEF:
				temp = descriptor->GetBrief();
				if (!temp.empty())
				{
					temp.pop_back();
				}
				descriptor->SetBrief(temp);
				break;
			}
			break;
		case ::Command::RED:
			switch (current)
			{
			case EditScenarioDescriptorItem::SCENARIO_NAME:
				descriptor->SetName("");
				break;
			case EditScenarioDescriptorItem::BRIEF:
				descriptor->SetBrief("");
				break;
			default:
				::Application::SetUIState(::UIState::EDIT_SCENARIO);;
				break;
			}
			break;
		case ::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case ::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		auto descriptor = ::game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex());
		::data::Strings::Set(TEXT_NAME_SCENARIO_NAME, descriptor->GetName());
		::data::Strings::Set(TEXT_NAME_BRIEF, descriptor->GetBrief());
		UpdateMenuItems(items, current);
	}

	static void OnTextInput(const std::string& text)
	{
		auto descriptor = ::game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex());
		switch (current)
		{
		case EditScenarioDescriptorItem::SCENARIO_NAME:
			descriptor->SetName(descriptor->GetName() + text);
			break;
		case EditScenarioDescriptorItem::BRIEF:
			descriptor->SetBrief(descriptor->GetBrief() + text);
			break;
		}

	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_SCENARIO_DESCRIPTOR, OnCommand);
		::Application::SetRenderHandler(::UIState::EDIT_SCENARIO_DESCRIPTOR, OnDraw);
		::Application::SetUpdateHandler(::UIState::EDIT_SCENARIO_DESCRIPTOR, OnUpdate);
		::Application::SetTextInputHandler(::UIState::EDIT_SCENARIO_DESCRIPTOR, OnTextInput);
	}
}