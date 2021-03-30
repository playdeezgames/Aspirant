#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
#include "Application.Command.h"
#include "Application.TextInput.h"
#include "Application.Update.h"
#include "Application.UIState.h"
namespace state::editor::ScenarioDescriptor
{
	const std::string LAYOUT_NAME = "State.Editor.ScenarioDescriptor";
	const std::string MENU_ID = "ScenarioDescriptor";
	const std::string SCENARIO_NAME_TEXT_ID = "ScenarioName";
	const std::string BRIEF_TEXT_ID = "Brief";

	enum class EditScenarioDescriptorItem
	{
		SCENARIO_NAME,
		BRIEF,
		BACK
	};

	static EditScenarioDescriptorItem GetCurrentItem()
	{
		return (EditScenarioDescriptorItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME, MENU_ID).value();
	}

	void ActivateItem()
	{
		switch (GetCurrentItem())
		{
		case EditScenarioDescriptorItem::BACK:
			game::ScenarioDescriptors::Save();
			::application::UIState::SetUIState(::UIState::EDIT_SCENARIO);
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
			switch (GetCurrentItem())
			{
			case EditScenarioDescriptorItem::SCENARIO_NAME:
				temp = descriptor.value().GetName();
				if (!temp.empty())
				{
					temp.pop_back();
				}
				descriptor.value().SetName(temp);
				break;
			case EditScenarioDescriptorItem::BRIEF:
				temp = descriptor.value().GetBrief();
				if (!temp.empty())
				{
					temp.pop_back();
				}
				descriptor.value().SetBrief(temp);
				break;
			}
			break;
		case ::Command::RED:
			switch (GetCurrentItem())
			{
			case EditScenarioDescriptorItem::SCENARIO_NAME:
				descriptor.value().SetName("");
				break;
			case EditScenarioDescriptorItem::BRIEF:
				descriptor.value().SetBrief("");
				break;
			default:
				game::ScenarioDescriptors::Save();
				::application::UIState::SetUIState(::UIState::EDIT_SCENARIO);;
				break;
			}
			break;
		case ::Command::UP:
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
		auto descriptor = ::game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex());
		graphics::Layouts::SetTextText(LAYOUT_NAME, SCENARIO_NAME_TEXT_ID, descriptor.value().GetName());
		graphics::Layouts::SetTextText(LAYOUT_NAME, BRIEF_TEXT_ID, descriptor.value().GetBrief());
	}

	static void OnTextInput(const std::string& text)
	{
		auto descriptor = ::game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex());
		switch (GetCurrentItem())
		{
		case EditScenarioDescriptorItem::SCENARIO_NAME:
			descriptor.value().SetName(descriptor.value().GetName() + text);
			break;
		case EditScenarioDescriptorItem::BRIEF:
			descriptor.value().SetBrief(descriptor.value().GetBrief() + text);
			break;
		}
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::EDIT_SCENARIO_DESCRIPTOR, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_SCENARIO_DESCRIPTOR, LAYOUT_NAME);
		::application::Update::AddHandler(::UIState::EDIT_SCENARIO_DESCRIPTOR, OnUpdate);
		::application::TextInput::SetHandler(::UIState::EDIT_SCENARIO_DESCRIPTOR, OnTextInput);
	}
}