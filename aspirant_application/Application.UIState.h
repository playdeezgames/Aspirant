#pragma once
#include "UIState.h"
namespace application::UIState
{
	void SetUIState(const ::UIState&);
	const ::UIState& GetUIState();
}