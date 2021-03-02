#include "EditScenarioSelectorStateHandler.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "EditScenarioSelector";

	bool EditScenarioSelectorStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::BACK:
		case Command::RED:
			SetUIState(UIState::START_EDITOR);
			break;
		}
		return true;
	}

	EditScenarioSelectorStateHandler::EditScenarioSelectorStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		tggd::common::LayoutManager& layoutManager
	)
		: CommonStateHandler(parent, currentState, UIState::EDIT_SCENARIO_SELECTOR, layoutManager.GetDescriptor(LAYOUT_NAME))
	{

	}

}