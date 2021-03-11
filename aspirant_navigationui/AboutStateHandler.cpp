#include "AboutStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "Utility.h"
namespace aspirant::navigationui
{
	const std::string LAYOUT_NAME = "About";

	AboutStateHandler::AboutStateHandler
	(
		MessageHandler* parent,
		const aspirant::commonui::UIContext& uiContext
	)
		: aspirant::commonui::CommonStateHandler(parent, aspirant::commonui::UIState::ABOUT, LAYOUT_NAME, uiContext)
	{
	}

	bool AboutStateHandler::OnCommand(const aspirant::commonui::Command& command)
	{
		switch (command)
		{
		case aspirant::commonui::Command::GREEN:
		case aspirant::commonui::Command::RED:
		case aspirant::commonui::Command::BACK:
		case aspirant::commonui::Command::START:
			SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			break;
		}
		return true;
	}
}