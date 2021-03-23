#include "StartEditorStateHandler.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include "MenuItemDescriptor.h"
#include <map>
#include "Data.Strings.h"
#include "ScenarioDescriptorManager.h"
#include <sstream>
#include "Data.JSON.h"
#include "EditorScenarioSelector.h"
namespace aspirant::editorui::StartEditorStateHandler
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
	static std::map<StartEditorItem, aspirant::commonui::MenuItemDescriptor<StartEditorItem>> items;

	static void CreateScenarioFile(const std::string& fileName)
	{
		nlohmann::json properties;
		properties["rooms"] = nlohmann::json({});//TODO: magic string
		data::JSON::Save(fileName, properties);
	}


	static void CreateNewScenario()
	{
		int scenarioId = aspirant::game::ScenarioDescriptorManager::GetNextId();
		std::stringstream ss;
		ss << "scenarios/scenario_" << scenarioId << ".json";//TODO: magic string
		aspirant::game::ScenarioDescriptor* descriptor = new aspirant::game::ScenarioDescriptor
		(
			scenarioId,
			"New Scenario",//TODO: magic string
			"The best scenario ever!",//TODO: magic string
			ss.str()
		);
		CreateScenarioFile(ss.str());
		aspirant::editor::context::EditorScenarioSelector::SetIndex(aspirant::game::ScenarioDescriptorManager::Add(descriptor));
		aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
	}

	static void ActivateItem()
	{
		switch (current)
		{
		case StartEditorItem::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::START_GAME);
			break;
		case StartEditorItem::NEW:
			CreateNewScenario();
			break;
		case StartEditorItem::OPEN:
			//TODO: what to do when there are no scenarios to open?
			aspirant::Application::SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR);
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
			aspirant::Application::SetUIState(aspirant::commonui::UIState::START_GAME);
			break;
		case aspirant::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
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
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::START_EDITOR, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::START_EDITOR, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::START_EDITOR, OnUpdate);
		items[StartEditorItem::NEW] = 
			aspirant::commonui::MenuItemDescriptor<StartEditorItem>(START_EDITOR_NEW_COLOR_NAME, StartEditorItem::BACK, StartEditorItem::OPEN);
		items[StartEditorItem::OPEN]=
			aspirant::commonui::MenuItemDescriptor<StartEditorItem>(START_EDITOR_OPEN_COLOR_NAME, StartEditorItem::NEW, StartEditorItem::BACK);
		items[StartEditorItem::BACK]=
			aspirant::commonui::MenuItemDescriptor<StartEditorItem>(START_EDITOR_BACK_COLOR_NAME, StartEditorItem::OPEN, StartEditorItem::NEW);

	}
}
