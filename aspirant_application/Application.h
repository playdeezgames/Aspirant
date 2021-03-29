#pragma once
#include "UIState.h"
#include "Command.h"
#include <string>
#include <SDL.h>
#include "Common.XY.h"
namespace Application
{
	void SetUIState(const ::UIState&);
	const UIState& GetUIState();
	void SetRenderLayout(const UIState&, const std::string&);

}
