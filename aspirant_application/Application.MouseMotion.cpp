#include "Application.MouseMotion.h"
#include <map>
#include "Application.h"
namespace application::MouseMotion
{
	static std::map<UIState, Handler> handlers;

	void Handle(const SDL_MouseMotionEvent& evt)
	{
		auto handler = handlers.find(Application::GetUIState());
		if (handler != handlers.end())
		{
			handler->second({ evt.x, evt.y });
		}
	}

	void SetHandler(const UIState& state, Handler handler)
	{
		handlers[state] = handler;
	}
}