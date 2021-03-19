#pragma once
#include "MessageHandler.h"
#include "UIState.h"
#include "MSetUIState.h"
#include "UIContext.h"
namespace aspirant::commonui
{
	class UIStateMessageHandler : public tggd::common::MessageHandler
	{
		UIStateMessageHandler() = delete;
		UIStateMessageHandler(const UIStateMessageHandler&) = delete;
		UIStateMessageHandler(UIStateMessageHandler&&) = delete;
		UIStateMessageHandler& operator=(const UIStateMessageHandler&) = delete;
		UIStateMessageHandler& operator=(UIStateMessageHandler&&) = delete;
	private:
		UIState filterState;
		const UIContext& uiContext;
	protected:
		const UIContext& GetUIContext() const
		{
			return uiContext;
		}
		bool IsEnabled() const
		{
			return (GetUIContext().GetUIState() == filterState);
		}
		void SetUIState(const UIState& newState)
		{
			Handle(MSetUIState(newState));
		}
	public:
		UIStateMessageHandler
		(
			MessageHandler* parent, 
			const UIState& filterState,
			const UIContext& uiContext
		)
			: tggd::common::MessageHandler(parent)
			, filterState(filterState)
			, uiContext(uiContext)
		{

		}
	};
}
