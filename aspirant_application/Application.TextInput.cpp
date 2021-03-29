#include "Application.TextInput.h"
#include <map>
#include "Application.h"
namespace application::TextInput
{
	static std::map<::UIState, Handler> textInputHandlers;

	void Handle(const SDL_TextInputEvent& evt)
	{
		auto handler = textInputHandlers.find(::Application::GetUIState());
		if (handler != textInputHandlers.end())
		{
			handler->second(evt.text);
		}
	}

	void SetHandler(const ::UIState& state, Handler handler)
	{
		textInputHandlers[state] = handler;
	}
}