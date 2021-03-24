#include "Aspirant.State.Editor.Start.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "Graphics.Layouts.h"
#include "Aspirant.MenuItem.h"
#include <map>
#include "Data.Strings.h"
#include "Game.ScenarioDescriptors.h"
#include <sstream>
#include "Data.JSON.h"
#include "Aspirant.Context.Editor.Scenarios.h"
namespace aspirant::state::editor::Start
{
	const std::string START_EDITOR_NEW_COLOR_NAME = "StartEditor.Color.New";
	const std::string START_EDITOR_BACK_COLOR_NAME = "StartEditor.Color.Back";
	const std::string START_EDITOR_OPEN_COLOR_NAME = "StartEditor.Color.Open";
	const std::string LAYOUT_NAME = "StartEditor";

	enum class StartEditorItem
	{
		NEW,
		OPEN,
		BACK
	};

	static StartEditorItem current = StartEditorItem::BACK;
	static std::map<StartEditorItem, aspirant::MenuItem<StartEditorItem>> items;

	static void CreateScenarioFile(const std::string& fileName)
	{
		nlohmann::json properties;
		properties["rooms"] = nlohmann::json({});//TODO: magic string
		data::JSON::Save(fileName, properties);
	}


	static void CreateNewScenario()
	{
		int scenarioId = ::game::ScenarioDescriptors::GetNextId();
		std::stringstream ss;
		ss << "scenarios/scenario_" << scenarioId << ".json";//TODO: magic string
		::game::ScenarioDescriptor* descriptor = new ::game::ScenarioDescriptor
		(
			scenarioId,
			"New Scenario",//TODO: magic string
			"The best scenario ever!",//TODO: magic string
			ss.str()
		);
		CreateScenarioFile(ss.str());
		aspirant::context::editor::Scenarios::SetIndex(::game::ScenarioDescriptors::Add(descriptor));
		aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO);
	}

	static void ActivateItem()
	{
		switch (current)
		{
		case StartEditorItem::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::START_GAME);
			break;
		case StartEditorItem::NEW:
			CreateNewScenario();
			break;
		case StartEditorItem::OPEN:
			//TODO: what to do when there are no scenarios to open?
			aspirant::Application::SetUIState(aspirant::UIState::EDIT_SCENARIO_SELECTOR);
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
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::START_GAME);
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
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::UIState::START_EDITOR, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::START_EDITOR, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::START_EDITOR, OnUpdate);
		items[StartEditorItem::NEW] = 
			aspirant::MenuItem<StartEditorItem>(START_EDITOR_NEW_COLOR_NAME, StartEditorItem::BACK, StartEditorItem::OPEN);
		items[StartEditorItem::OPEN]=
			aspirant::MenuItem<StartEditorItem>(START_EDITOR_OPEN_COLOR_NAME, StartEditorItem::NEW, StartEditorItem::BACK);
		items[StartEditorItem::BACK]=
			aspirant::MenuItem<StartEditorItem>(START_EDITOR_BACK_COLOR_NAME, StartEditorItem::OPEN, StartEditorItem::NEW);

	}
}