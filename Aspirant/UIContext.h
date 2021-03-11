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
		const tggd::graphics::LayoutManager& layoutManager;
		tggd::data::StringManager& stringManager;
	public:
		UIContext
		(
			const UIState& uiState,
			const tggd::graphics::LayoutManager& layoutManager,
			tggd::data::StringManager& stringManager
		) 
			: uiState(uiState)
			, layoutManager(layoutManager)
			, stringManager(stringManager)
		{}
		const UIState& GetUIState() const
		{
			return uiState;
		}
		const tggd::graphics::LayoutManager& GetLayoutManager() const
		{
			return layoutManager;
		}
		tggd::data::StringManager& GetStringManager() const
		{
			return stringManager;
		}
	};
}
