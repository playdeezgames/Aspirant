#include "Application.h"
#include "Graphics.Layouts.h"
#include "json.hpp"
#include "Game.Properties.h"
#include "Common.Properties.h"
#include "Data.JSON.h"
#include "Game.ScenarioDescriptors.h"
#include "Context.Editor.Scenarios.h"
#include "Application.Command.h"
#include "Application.UIState.h"
namespace state::editor::Start
{
	const std::string LAYOUT_NAME = "State.Editor.Start";
	const std::string MENU_ID = "Start";

	enum class StartEditorItem
	{
		NEW,
		OPEN,
		BACK
	};

	//TODO: this belongs someplace else vvv
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

	//TODO: this belongs someplace else vvv
	static void CreateNewScenario()
	{
		int scenarioId = ::game::ScenarioDescriptors::GetNextId();
		::context::editor::Scenarios::SetIndex(::game::ScenarioDescriptors::Add());
		CreateScenarioFile(game::ScenarioDescriptors::Get(context::editor::Scenarios::GetIndex()).value().GetFileName());
	}

	static void ActivateItem()
	{
		switch ((StartEditorItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME, MENU_ID).value())
		{
		case StartEditorItem::BACK:
			::application::UIState::Write(::UIState::START_GAME);
			break;
		case StartEditorItem::NEW:
			CreateNewScenario();
			::application::UIState::Write(::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		case StartEditorItem::OPEN:
			if (game::ScenarioDescriptors::GetCount() > 0)
			{
				::application::UIState::Write(::UIState::EDIT_SCENARIO_SELECTOR);
			}
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case ::Command::BACK:
			::application::UIState::Write(::UIState::START_GAME);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	void Start()
	{
		::application::Command::SetHandler(
			::UIState::START_EDITOR,
			OnCommand);
		::Application::SetRenderLayout(
			::UIState::START_EDITOR,
			LAYOUT_NAME);
	}
}