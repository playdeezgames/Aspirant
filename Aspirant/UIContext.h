#pragma once
#include "UIState.h"
namespace aspirant
{
	class UIContext
	{
	private:
		const UIState& uiState;
	public:
		UIContext(const UIState& uiState) 
			: uiState(uiState)
		{}
		const UIState& GetUIState() const
		{
			return uiState;
		}
	};
}
