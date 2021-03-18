#pragma once
#include "MGeneric.h"
#include <SDL.h>
namespace tggd::common
{
	class MEvent : public MGeneric
	{
		MEvent() = delete;
		MEvent(const MEvent&) = delete;
		MEvent(MEvent&&) = delete;
		MEvent& operator=(const MEvent&) = delete;
		MEvent& operator=(MEvent&&) = delete;
	private:
		const SDL_Event& _event;
		static void MSGID_SdlEvent() {}
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
		static bool IsMEvent(const MGeneric* message)
		{
			return message && message->GetId() == MSGID_SdlEvent;
		}
		static const MEvent* ToMEvent(const MGeneric* message)
		{
			return static_cast<const tggd::common::MEvent*>(message);
		}
	};
}
