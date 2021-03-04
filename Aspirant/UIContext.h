#pragma once
#include "UIState.h"
#include "LayoutManager.h"
#include "StringManager.h"
namespace aspirant
{
	class UIContext
	{
	private:
		const UIState& uiState;
		const tggd::common::LayoutManager& layoutManager;
		tggd::common::StringManager& stringManager;
	public:
		UIContext
		(
			const UIState& uiState,
			const tggd::common::LayoutManager& layoutManager,
			tggd::common::StringManager& stringManager
		) 
			: uiState(uiState)
			, layoutManager(layoutManager)
			, stringManager(stringManager)
		{}
		const UIState& GetUIState() const
		{
			return uiState;
		}
		const tggd::common::LayoutManager& GetLayoutManager() const
		{
			return layoutManager;
		}
		tggd::common::StringManager& GetStringManager() const
		{
			return stringManager;
		}
	};
}
