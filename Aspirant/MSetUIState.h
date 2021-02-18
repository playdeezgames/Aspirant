#pragma once
#include "MGeneric.h"
#include "UIState.h"
namespace aspirant
{
	class MSetUIState : public tggd::common::MGeneric
	{
	private:
		UIState state;
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
		static void MSGID_SetUIState() {}
	};
}
