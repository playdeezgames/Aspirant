#pragma once
#include <SDL.h>
namespace tggd::common
{
	class EventHandler
	{
	protected:
		virtual void OnEvent(const SDL_Event&) = 0;
	public:
		static void MSGID_SdlEvent() {}
	};
}
