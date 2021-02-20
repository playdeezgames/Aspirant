#include "MainMenuStateHandler.h"
#include "MRender.h"
namespace aspirant
{
	bool MainMenuStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		SDL_RenderClear(renderer);
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

	MainMenuStateHandler::MainMenuStateHandler
	(
		MessageHandler* parent,
		const UIState& currentState
	)
		: UIStateMessageHandler(parent, currentState, UIState::MainMenu)
	{

	}
}