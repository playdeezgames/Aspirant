#include "MainMenuStateHandler.h"
#include "MRender.h"
namespace aspirant
{
	bool MainMenuStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		SDL_RenderClear(renderer);
		layout->Draw(renderer);
		return true;
	}

	bool MainMenuStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		return false;
	}

	const std::string LAYOUT_NAME = "MainMenu";

	MainMenuStateHandler::MainMenuStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState,
		const tggd::common::LayoutManager& layoutManager
	)
		: UIStateMessageHandler(parent, currentState, UIState::MainMenu)
		, layout(layoutManager.GetDescriptor(LAYOUT_NAME))
	{

	}
}