#include "Aspirant.State.Editor.ScenarioDescriptor.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
#include "MenuItemDescriptor.h"
#include "Aspirant.Context.Editor.Scenarios.h"
#include "Data.Strings.h"
#include "ScenarioDescriptorManager.h"
namespace aspirant::state::editor::ScenarioDescriptor
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
	static std::map<EditScenarioDescriptorItem, aspirant::commonui::MenuItemDescriptor<EditScenarioDescriptorItem>> items;

	void ActivateItem()
	{
		switch (current)
		{
		case EditScenarioDescriptorItem::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO);
			break;
		}
	}

	static void OnCommand(const aspirant::Command& command)
	{
		auto descriptor = aspirant::game::ScenarioDescriptorManager::Get(aspirant::context::editor::Scenarios::GetIndex());
		switch (command)
		{
		case aspirant::Command::BACK:
			switch (current)
			{
			case EditScenarioDescriptorItem::SCENARIO_NAME:
				descriptor->SetName("");
				break;
			case EditScenarioDescriptorItem::BRIEF:
				descriptor->SetBrief("");
				break;
			default:
				aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO);;
				break;
			}
			break;
		case aspirant::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case aspirant::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case aspirant::Command::GREEN:
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
		auto descriptor = aspirant::game::ScenarioDescriptorManager::Get(aspirant::context::editor::Scenarios::GetIndex());
		::data::Strings::Set(TEXT_NAME_SCENARIO_NAME, descriptor->GetName());
		::data::Strings::Set(TEXT_NAME_BRIEF, descriptor->GetBrief());
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}

	static void OnTextInput(const std::string& text)
	{
		auto descriptor = aspirant::game::ScenarioDescriptorManager::Get(aspirant::context::editor::Scenarios::GetIndex());
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
		aspirant::Application::SetCommandHandler(aspirant::UIState::EDIT_SCENARIO_DESCRIPTOR, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::EDIT_SCENARIO_DESCRIPTOR, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::EDIT_SCENARIO_DESCRIPTOR, OnUpdate);
		aspirant::Application::SetTextInputHandler(aspirant::UIState::EDIT_SCENARIO_DESCRIPTOR, OnTextInput);
		items[EditScenarioDescriptorItem::SCENARIO_NAME]= aspirant::commonui::MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_SCENARIO_NAME, EditScenarioDescriptorItem::BACK, EditScenarioDescriptorItem::BRIEF);
		items[EditScenarioDescriptorItem::BRIEF]= aspirant::commonui::MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME, EditScenarioDescriptorItem::BACK);
		items[EditScenarioDescriptorItem::BACK]= aspirant::commonui::MenuItemDescriptor<EditScenarioDescriptorItem>(COLOR_NAME_BACK, EditScenarioDescriptorItem::BRIEF, EditScenarioDescriptorItem::SCENARIO_NAME);
	}

}