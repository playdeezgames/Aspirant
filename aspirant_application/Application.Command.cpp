#include "Application.Command.h"
#include "UIState.h"
#include <map>
#include "Application.h"
namespace application::Command
{
	static std::map<::UIState, Handler> commandHandlers;

	void Handle(const ::Command& command)
	{
		auto handler = commandHandlers.find(::Application::GetUIState());
		if (handler != commandHandlers.end())
		{
			handler->second(command);
		}
	}

	void SetHandler(const ::UIState& state, Handler handler)
	{
		commandHandlers[state] = handler;
	}
}