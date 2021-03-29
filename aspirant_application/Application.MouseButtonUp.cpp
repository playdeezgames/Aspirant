#include "Application.MouseButtonUp.h"
#include <map>
#include "Application.h"
namespace application::MouseButtonUp
{
	static std::map<UIState, Handler> handlers;

	void SetHandler(const UIState& state, Handler handler)
	{
		handlers[state] = handler;
	}

	void Handle(const SDL_MouseButtonEvent& evt)
	{
		auto iter = handlers.find(Application::GetUIState());
		if (iter != handlers.end())
		{
			iter->second(common::XY<Sint32>(evt.x, evt.y), evt.button);
		}
	}
}
