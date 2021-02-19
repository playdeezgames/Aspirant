#include "SplashStateHandler.h"
#include "MRender.h"
namespace aspirant
{
	const std::string SPRITE_NAME = "Splash";
	const int SPRITE_X = 0;
	const int SPRITE_Y = 0;

	bool SplashStateHandler::OnDraw(SDL_Renderer* renderer) const
	{
		spriteManager.GetSprite(SPRITE_NAME)->Draw(renderer, tggd::common::XY<int>(SPRITE_X, SPRITE_Y));
		return false;
	}

	bool SplashStateHandler::OnMessage(const tggd::common::MGeneric* message)
	{
		if (message->GetId() == tggd::common::MRender::MSGID_Draw)
		{
			return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
		}
		return false;
	}
}