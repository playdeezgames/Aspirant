#pragma once
#include "MGeneric.h"
#include <SDL.h>
namespace tggd::common
{
	class MEvent : public MGeneric
	{
	private:
		const SDL_Event& _event;
	public:
		MEvent(const SDL_Event& evt)
			: MGeneric(MSGID_SdlEvent)
			, _event(evt)
		{

		}
		const SDL_Event& GetEvent() const
		{
			return _event;
		}
		static void MSGID_SdlEvent() {}
	};
}
