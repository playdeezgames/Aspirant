#include "EditScenarioSelectorStateHandler.h"
#include "AspirantApplication.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "ScenarioDescriptorManager.h"
#include "EditorScenarioSelector.h"
#include "StringManager.h"
#include <sstream>
#include "EditorContext.h"
#include "JSONUtility.h"
namespace aspirant::editorui::EditScenarioSelectorStateHandler
{
	const std::string LAYOUT_NAME = "EditScenarioSelector";
	const std::string TEXT_INDEX_STRING_NAME = "EditScenarioSelector.Text.Index";
	const std::string TEXT_ID_STRING_NAME = "EditScenarioSelector.Text.Id";
	const std::string TEXT_NAME_STRING_NAME = "EditScenarioSelector.Text.Name";
	const std::string TEXT_BRIEF_STRING_NAME = "EditScenarioSelector.Text.Brief";

	static void OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::START_EDITOR);
			break;
		case aspirant::commonui::Command::NEXT:
		case aspirant::commonui::Command::RIGHT:
			aspirant::editor::context::EditorScenarioSelector::Next();
			break;
		case aspirant::commonui::Command::PREVIOUS:
		case aspirant::commonui::Command::LEFT:
			aspirant::editor::context::EditorScenarioSelector::Previous();
			break;
		case aspirant::commonui::Command::GREEN:
			aspirant::editor::context::EditorContext::LoadScenario();
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void UpdateIndexText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << "Scenario " << (aspirant::editor::context::EditorScenarioSelector::GetIndex() + 1) << "/" << aspirant::game::ScenarioDescriptorManager::GetCount();
			tggd::data::StringManager::Set(TEXT_INDEX_STRING_NAME, ss.str());
		}
		else
		{
			tggd::data::StringManager::Set(TEXT_INDEX_STRING_NAME, "No Scenarios");//TODO: magic string
		}
	}

	static void UpdateNameText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			tggd::data::StringManager::Set(TEXT_NAME_STRING_NAME, scenario->GetName());
		}
		else
		{
			tggd::data::StringManager::Set(TEXT_NAME_STRING_NAME, "-");//TODO: magic string
		}
	}

	static void UpdateIdText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			std::stringstream ss;
			ss << scenario->GetId();
			tggd::data::StringManager::Set(TEXT_ID_STRING_NAME, ss.str());
		}
		else
		{
			tggd::data::StringManager::Set(TEXT_ID_STRING_NAME, "-");//TODO: magic string
		}

	}

	static void UpdateBriefText(const aspirant::game::ScenarioDescriptor* scenario)
	{
		if (scenario)
		{
			tggd::data::StringManager::Set(TEXT_BRIEF_STRING_NAME, scenario->GetBrief());
		}
		else
		{
			tggd::data::StringManager::Set(TEXT_BRIEF_STRING_NAME, "-");//TODO: magic string
		}
	}


	static void OnUpdate(const Uint32& ticks)
	{
		auto scenario = aspirant::game::ScenarioDescriptorManager::Get(aspirant::editor::context::EditorScenarioSelector::GetIndex());
		UpdateBriefText(scenario);
		UpdateIdText(scenario);
		UpdateIndexText(scenario);
		UpdateNameText(scenario);
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR, OnUpdate);
	}
}
