#include "AboutStateHandler.h"
#include "MRender.h"
#include "MCommand.h"
#include "Utility.h"
namespace aspirant
{
	const std::string LAYOUT_NAME = "About";

	AboutStateHandler::AboutStateHandler
	(
		MessageHandler* parent,
		tggd::common::LayoutManager& layoutManager,
		const UIContext& uiContext
	)
		: CommonStateHandler(parent, UIState::ABOUT, layoutManager.GetDescriptor(LAYOUT_NAME), uiContext)
	{
	}

	bool AboutStateHandler::OnCommand(const Command& command)
	{
		switch (command)
		{
		case Command::GREEN:
		case Command::RED:
		case Command::BACK:
		case Command::START:
			SetUIState(UIState::MAIN_MENU);
			break;
		}
		return true;
	}
}