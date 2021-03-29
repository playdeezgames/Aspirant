#include "Application.Command.h"
#include "UIState.h"
#include <map>
#include "Application.h"
namespace application::Command
{
	static std::map<::UIState, Handler> handlers;

	void Handle(const ::Command& command)
	{
		auto handler = handlers.find(::Application::GetUIState());
		if (handler != handlers.end())
		{
			handler->second(command);
		}
	}

	void SetHandler(const ::UIState& state, Handler handler)
	{
		handlers[state] = handler;
	}
}