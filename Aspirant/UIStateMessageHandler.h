#pragma once
#include "MessageHandler.h"
#include "UIState.h"
namespace aspirant
{
	class UIStateMessageHandler : public tggd::common::MessageHandler
	{
	private:
		UIState filterState;
		const UIState& currentState;
	protected:
		bool IsEnabled() const
		{
			return (currentState == filterState);
		}
	public:
		UIStateMessageHandler(MessageHandler* parent, const UIState& currentState, const UIState& filterState)
			: tggd::common::MessageHandler(parent)
			, currentState(currentState)
			, filterState(filterState)
		{

		}
	};
}
