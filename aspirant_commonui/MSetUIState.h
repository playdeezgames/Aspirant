#pragma once
#include "MGeneric.h"
#include "UIState.h"
namespace aspirant::commonui
{
	class MSetUIState : public tggd::common::MGeneric
	{
	private:
		UIState state;
		static void MSGID_SetUIState() {}
	public:
		MSetUIState(const UIState& state)
			: MGeneric(MSGID_SetUIState)
			, state(state)
		{

		}
		const UIState& GetState() const
		{
			return state;
		}
		static bool Is(const tggd::common::MGeneric* message)
		{
			return message && message->GetId() == MSGID_SetUIState;
		}
		static const MSetUIState* From(const tggd::common::MGeneric* message)
		{
			return static_cast<const aspirant::commonui::MSetUIState*>(message);
		}
	};
}
