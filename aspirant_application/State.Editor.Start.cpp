#include "State.Editor.Start.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "MenuItem.h"
#include <map>
#include "Data.Strings.h"
#include "Game.ScenarioDescriptors.h"
#include <sstream>
#include "Data.JSON.h"
#include "Context.Editor.Scenarios.h"
namespace state::editor::Start
{
	const std::string START_EDITOR_NEW_COLOR_NAME = "StartEditor.Color.New";
	const std::string START_EDITOR_BACK_COLOR_NAME = "StartEditor.Color.Back";
	const std::string START_EDITOR_OPEN_COLOR_NAME = "StartEditor.Color.Open";
	const std::string LAYOUT_NAME = "StartEditor";
	const std::string PROPERTY_ROOMS = "rooms";

	enum class StartEditorItem
	{
		NEW,
		OPEN,
		BACK
	};

	static StartEditorItem current = StartEditorItem::BACK;
	static std::map<StartEditorItem, ::MenuItem<StartEditorItem>> items =
	{
		{StartEditorItem::NEW,
			::MenuItem<StartEditorItem>(
				START_EDITOR_NEW_COLOR_NAME,
				StartEditorItem::BACK,
				StartEditorItem::OPEN)},
		{StartEditorItem::OPEN,
			::MenuItem<StartEditorItem>(
				START_EDITOR_OPEN_COLOR_NAME,
				StartEditorItem::NEW,
				StartEditorItem::BACK)},
		{StartEditorItem::BACK,
			::MenuItem<StartEditorItem>(
				START_EDITOR_BACK_COLOR_NAME,
				StartEditorItem::OPEN,
				StartEditorItem::NEW)}
	};

	static void CreateScenarioFile(const std::string& fileName)
	{
		nlohmann::json properties;
		properties[PROPERTY_ROOMS] = nlohmann::json({});
		data::JSON::Save(fileName, properties);
	}

	const std::string SCENARIO_FILE_PREFIX = "scenarios/scenario_";
	const std::string SCENARIO_FILE_SUFFIX = ".json";
	const std::string DEFAULT_SCENARIO_NAME = "New Scenario";
	const std::string DEFAULT_SCENARIO_BRIEF = "The best scenario ever!";

	static void CreateNewScenario()
	{
		int scenarioId = ::game::ScenarioDescriptors::GetNextId();
		std::stringstream ss;
		ss << SCENARIO_FILE_PREFIX << scenarioId << SCENARIO_FILE_SUFFIX;
		::game::ScenarioDescriptor* descriptor = new ::game::ScenarioDescriptor
		(
			scenarioId,
			DEFAULT_SCENARIO_NAME,
			DEFAULT_SCENARIO_BRIEF,
			ss.str()
		);
		CreateScenarioFile(ss.str());
		::context::editor::Scenarios::SetIndex(::game::ScenarioDescriptors::Add(descriptor));
		::Application::SetUIState(::UIState::EDIT_SCENARIO);
	}

	static void ActivateItem()
	{
		switch (current)
		{
		case StartEditorItem::BACK:
			::Application::SetUIState(::UIState::START_GAME);
			break;
		case StartEditorItem::NEW:
			CreateNewScenario();
			break;
		case StartEditorItem::OPEN:
			::Application::SetUIState(::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case ::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::START_GAME);
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
		UpdateMenuItems(items, current);
	}

	void Start()
	{
		::Application::SetCommandHandler(
			::UIState::START_EDITOR,
			OnCommand);
		::Application::SetRenderHandler(
			::UIState::START_EDITOR,
			OnDraw);
		::Application::SetUpdateHandler(
			::UIState::START_EDITOR,
			OnUpdate);
	}
}