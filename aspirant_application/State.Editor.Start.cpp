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
#include "Common.Properties.h"
#include "Game.Properties.h"
namespace state::editor::Start
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
		nlohmann::json model;
		model[game::Properties::AVATAR] = nlohmann::json({});
		auto& avatarModel = model[game::Properties::AVATAR];
		avatarModel[game::Properties::ROOM] = "";
		avatarModel[common::Properties::X] = 0;
		avatarModel[common::Properties::Y] = 0;
		model[game::Properties::ROOMS] = nlohmann::json({});
		data::JSON::Save(fileName, model);
	}

	static void CreateNewScenario()
	{
		int scenarioId = ::game::ScenarioDescriptors::GetNextId();
		::context::editor::Scenarios::SetIndex(::game::ScenarioDescriptors::Add());
		CreateScenarioFile(game::ScenarioDescriptors::Get(context::editor::Scenarios::GetIndex()).GetFileName());
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
			::Application::SetUIState(::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		case StartEditorItem::OPEN:
			if (game::ScenarioDescriptors::GetCount() > 0)
			{
				::Application::SetUIState(::UIState::EDIT_SCENARIO_SELECTOR);
			}
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			MenuItem<StartEditorItem>::Previous(current, items);
			break;
		case ::Command::DOWN:
			MenuItem<StartEditorItem>::Next(current, items);
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
		graphics::Layouts::Draw(renderer, LAYOUT_NAME);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		MenuItem<StartEditorItem>::Update(items, current);
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