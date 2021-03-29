#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Game.ScenarioDescriptors.h"
#include "Context.Editor.Scenarios.h"
#include <sstream>
#include "Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Application.Command.h"
#include "Application.Update.h"
namespace state::editor::Scenarios
{
	const std::string LAYOUT_NAME = "State.Editor.Scenarios";
	const std::string INDEX_TEXT_ID = "Index";
	const std::string ID_TEXT_ID = "Id";
	const std::string NAME_TEXT_ID = "Name";
	const std::string BRIEF_TEXT_ID = "Brief";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(::UIState::START_EDITOR);
			break;
		case ::Command::NEXT:
		case ::Command::RIGHT:
			::context::editor::Scenarios::Next();
			break;
		case ::Command::PREVIOUS:
		case ::Command::LEFT:
			::context::editor::Scenarios::Previous();
			break;
		case ::Command::GREEN:
			::context::editor::Scenario::Load();
			::Application::SetUIState(::UIState::EDIT_SCENARIO);
			break;
		}
	}

	static void UpdateIndexText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << "Scenario " << (::context::editor::Scenarios::GetIndex() + 1) << "/" << ::game::ScenarioDescriptors::GetCount();
			graphics::Layouts::SetTextText(LAYOUT_NAME, INDEX_TEXT_ID, ss.str());
		}
		else
		{
			graphics::Layouts::SetTextText(LAYOUT_NAME, INDEX_TEXT_ID, "No Scenarios");
		}
	}

	static void UpdateNameText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			graphics::Layouts::SetTextText(LAYOUT_NAME, NAME_TEXT_ID, scenario->GetName());
		}
		else
		{
			graphics::Layouts::SetTextText(LAYOUT_NAME, NAME_TEXT_ID, "-");
		}
	}

	static void UpdateIdText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << scenario->GetId();
			graphics::Layouts::SetTextText(LAYOUT_NAME, ID_TEXT_ID, ss.str());

		}
		else
		{
			graphics::Layouts::SetTextText(LAYOUT_NAME, ID_TEXT_ID, "-");
		}

	}

	static void UpdateBriefText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			graphics::Layouts::SetTextText(LAYOUT_NAME, BRIEF_TEXT_ID, scenario->GetBrief());
		}
		else
		{
			graphics::Layouts::SetTextText(LAYOUT_NAME, BRIEF_TEXT_ID, "-");
		}
	}


	static void OnUpdate(const Uint32& ticks)
	{
		auto scenario = game::ScenarioDescriptors::Get(::context::editor::Scenarios::GetIndex()).value();
		UpdateBriefText(&scenario);
		UpdateIdText(&scenario);
		UpdateIndexText(&scenario);
		UpdateNameText(&scenario);
	}

	void Start()
	{
		::application::Command::SetHandler(::UIState::EDIT_SCENARIO_SELECTOR, OnCommand);
		::Application::SetRenderLayout(::UIState::EDIT_SCENARIO_SELECTOR, LAYOUT_NAME);
		::application::Update::AddHandler(::UIState::EDIT_SCENARIO_SELECTOR, OnUpdate);
	}
}
