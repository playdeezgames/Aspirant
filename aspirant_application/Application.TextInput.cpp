#include "Application.TextInput.h"
#include <map>
#include "Application.h"
namespace application::TextInput
{
	static std::map<::UIState, Handler> handlers;

	void Handle(const SDL_TextInputEvent& evt)
	{
		auto handler = handlers.find(::Application::GetUIState());
		if (handler != handlers.end())
		{
			handler->second(evt.text);
		}
	}

	void SetHandler(const ::UIState& state, Handler handler)
	{
		handlers[state] = handler;
	}
}