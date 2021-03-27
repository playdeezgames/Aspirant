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
	const std::string PROPERTY_AVATAR = "avatar";
	const std::string PROPERTY_ROOM = "room";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";

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
		model[PROPERTY_AVATAR] = nlohmann::json({});
		auto& avatarModel = model[PROPERTY_AVATAR];
		avatarModel[PROPERTY_ROOM] = "";
		avatarModel[PROPERTY_X] = 0;
		avatarModel[PROPERTY_Y] = 0;
		model[PROPERTY_ROOMS] = nlohmann::json({});
		data::JSON::Save(fileName, model);
	}

	static void CreateNewScenario()
	{
		int scenarioId = ::game::ScenarioDescriptors::GetNextId();
		::context::editor::Scenarios::SetIndex(::game::ScenarioDescriptors::Add());
		CreateScenarioFile(game::ScenarioDescriptors::Get(context::editor::Scenarios::GetIndex()).GetFileName());
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
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
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