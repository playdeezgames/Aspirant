#include "StartEditorStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
#include <sstream>
#include "Utility.h"
namespace aspirant::editorui
{

	const std::string START_EDITOR_NEW_COLOR_NAME = "StartEditor.Color.New";
	const std::string START_EDITOR_BACK_COLOR_NAME = "StartEditor.Color.Back";
	const std::string START_EDITOR_OPEN_COLOR_NAME = "StartEditor.Color.Open";
	const std::string LAYOUT_NAME = "StartEditor";

	StartEditorStateHandler::StartEditorStateHandler
	(
		MessageHandler* parent,
		EditorContext& editorContext,
		const aspirant::commonui::UIContext& uiContext
	)
		: EditorMenuStateHandler
		(
			parent,
			aspirant::commonui::UIState::START_EDITOR,
			aspirant::commonui::UIState::START_GAME,
			LAYOUT_NAME,
			StartEditorItem::BACK,
			uiContext,
			editorContext
		)
	{
		AddMenuItem
		(
			StartEditorItem::NEW,
			aspirant::commonui::MenuItemDescriptor<StartEditorItem>(START_EDITOR_NEW_COLOR_NAME, StartEditorItem::BACK, StartEditorItem::OPEN)
		);
		AddMenuItem
		(
			StartEditorItem::OPEN,
			aspirant::commonui::MenuItemDescriptor<StartEditorItem>(START_EDITOR_OPEN_COLOR_NAME, StartEditorItem::NEW, StartEditorItem::BACK)
		);
		AddMenuItem
		(
			StartEditorItem::BACK,
			aspirant::commonui::MenuItemDescriptor<StartEditorItem>(START_EDITOR_BACK_COLOR_NAME, StartEditorItem::OPEN, StartEditorItem::NEW)
		);
	}

	void StartEditorStateHandler::ActivateItem(const StartEditorItem& currentItem)
	{
		switch (currentItem)
		{
		case StartEditorItem::BACK:
			SetUIState(aspirant::commonui::UIState::START_GAME);
			break;
		case StartEditorItem::NEW:
			CreateNewScenario();
			break;
		case StartEditorItem::OPEN:
			//TODO: what to do when there are no scenarios to open?
			SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO_SELECTOR);
			break;
		}
	}

	void CreateScenarioFile(const std::string& fileName)
	{
		nlohmann::json properties;
		properties["rooms"] = nlohmann::json({});//TODO: magic string
		tggd::data::JSONUtility::SaveJSON(fileName, properties);
	}

	void StartEditorStateHandler::CreateNewScenario()
	{
		int scenarioId = GetEditorContext().GetScenarioSelector().GetAll().GetNextId();
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
		GetEditorContext().GetScenarioSelector().SetIndex(GetEditorContext().GetScenarioSelector() .GetAll().Add(descriptor));
		SetUIState(aspirant::commonui::UIState::EDIT_SCENARIO);
	}
}