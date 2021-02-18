#pragma once
#include "MGeneric.h"
#include "EventHandler.h"
#include <SDL.h>
namespace tggd::common
{
	class MEvent : public MGeneric
	{
	private:
		const SDL_Event& _event;
	public:
		MEvent(const SDL_Event& evt)
			: MGeneric(EventHandler::MSGID_SdlEvent)
			, _event(evt)
		{

		}
		const SDL_Event& GetEvent() const
		{
			return _event;
		}
	};
}
