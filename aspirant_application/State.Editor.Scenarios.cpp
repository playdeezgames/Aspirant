#include "Aspirant.State.Editor.Scenarios.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Game.ScenarioDescriptors.h"
#include "Aspirant.Context.Editor.Scenarios.h"
#include "Data.Strings.h"
#include <sstream>
#include "Aspirant.Context.Editor.Scenario.h"
#include "Data.JSON.h"
namespace aspirant::state::editor::Scenarios
{
	const std::string LAYOUT_NAME = "EditScenarioSelector";
	const std::string TEXT_INDEX_STRING_NAME = "EditScenarioSelector.Text.Index";
	const std::string TEXT_ID_STRING_NAME = "EditScenarioSelector.Text.Id";
	const std::string TEXT_NAME_STRING_NAME = "EditScenarioSelector.Text.Name";
	const std::string TEXT_BRIEF_STRING_NAME = "EditScenarioSelector.Text.Brief";

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::BACK:
			::Application::SetUIState(::UIState::START_EDITOR);
			break;
		case ::Command::NEXT:
		case ::Command::RIGHT:
			aspirant::context::editor::Scenarios::Next();
			break;
		case ::Command::PREVIOUS:
		case ::Command::LEFT:
			aspirant::context::editor::Scenarios::Previous();
			break;
		case ::Command::GREEN:
			aspirant::context::editor::Scenario::Load();
			::Application::SetUIState(::UIState::EDIT_SCENARIO);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void UpdateIndexText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << "Scenario " << (aspirant::context::editor::Scenarios::GetIndex() + 1) << "/" << ::game::ScenarioDescriptors::GetCount();
			::data::Strings::Set(TEXT_INDEX_STRING_NAME, ss.str());
		}
		else
		{
			::data::Strings::Set(TEXT_INDEX_STRING_NAME, "No Scenarios");//TODO: magic string
		}
	}

	static void UpdateNameText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			::data::Strings::Set(TEXT_NAME_STRING_NAME, scenario->GetName());
		}
		else
		{
			::data::Strings::Set(TEXT_NAME_STRING_NAME, "-");//TODO: magic string
		}
	}

	static void UpdateIdText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << scenario->GetId();
			::data::Strings::Set(TEXT_ID_STRING_NAME, ss.str());
		}
		else
		{
			::data::Strings::Set(TEXT_ID_STRING_NAME, "-");//TODO: magic string
		}

	}

	static void UpdateBriefText(const ::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			::data::Strings::Set(TEXT_BRIEF_STRING_NAME, scenario->GetBrief());
		}
		else
		{
			::data::Strings::Set(TEXT_BRIEF_STRING_NAME, "-");//TODO: magic string
		}
	}


	static void OnUpdate(const Uint32& ticks)
	{
		auto scenario = ::game::ScenarioDescriptors::Get(aspirant::context::editor::Scenarios::GetIndex());
		UpdateBriefText(scenario);
		UpdateIdText(scenario);
		UpdateIndexText(scenario);
		UpdateNameText(scenario);
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::EDIT_SCENARIO_SELECTOR, OnCommand);
		::Application::SetRenderHandler(::UIState::EDIT_SCENARIO_SELECTOR, OnDraw);
		::Application::SetUpdateHandler(::UIState::EDIT_SCENARIO_SELECTOR, OnUpdate);
	}
}
