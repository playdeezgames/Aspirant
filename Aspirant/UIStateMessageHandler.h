#pragma once
#include "MessageHandler.h"
#include "UIState.h"
#include "MSetUIState.h"
#include "UIContext.h"
namespace aspirant
{
	class UIStateMessageHandler : public tggd::common::MessageHandler
	{
	private:
		UIState filterState;
		const UIState& currentState;
		const UIContext& uiContext;
	protected:
		bool IsEnabled() const
		{
			return (currentState == filterState);
		}
		void SetUIState(const UIState& newState)
		{
			Handle(MSetUIState(newState));
		}
	public:
		UIStateMessageHandler
		(
			MessageHandler* parent, 
			const UIState& currentState, 
			const UIState& filterState,
			const UIContext& uiContext
		)
			: tggd::common::MessageHandler(parent)
			, currentState(currentState)
			, filterState(filterState)
			, uiContext(uiContext)
		{

		}
	};
}
