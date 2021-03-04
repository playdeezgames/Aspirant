#pragma once
#include "UIState.h"
#include "LayoutManager.h"
namespace aspirant
{
	class UIContext
	{
	private:
		const UIState& uiState;
		const tggd::common::LayoutManager& layoutManager;
	public:
		UIContext
		(
			const UIState& uiState,
			const tggd::common::LayoutManager& layoutManager
		) 
			: uiState(uiState)
			, layoutManager(layoutManager)
		{}
		const UIState& GetUIState() const
		{
			return uiState;
		}
		const tggd::common::LayoutManager& GetLayoutManager() const
		{
			return layoutManager;
		}
	};
}
