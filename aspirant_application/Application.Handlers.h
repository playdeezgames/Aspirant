#pragma once
#include <map>
#include "UIState.h"
#include "Application.h"
namespace application::Handlers
{
	template<typename THandler, typename TAction>
	void WithCurrent(const std::map<UIState, THandler> handlers, TAction action)
	{
		auto iter = handlers.find(Application::GetUIState());
		if (iter != handlers.end())
		{
			action(iter->second);
		}
	}
}