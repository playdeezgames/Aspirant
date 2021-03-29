#include "Application.MouseMotion.h"
#include <map>
#include "Application.h"
namespace application::MouseMotion
{
	static std::map<UIState, Handler> mouseMotionHandlers;

	void Handle(const SDL_MouseMotionEvent& evt)
	{
		auto handler = mouseMotionHandlers.find(Application::GetUIState());
		if (handler != mouseMotionHandlers.end())
		{
			handler->second({ evt.x, evt.y });
		}
	}

	void SetHandler(const UIState& state, Handler handler)
	{
		mouseMotionHandlers[state] = handler;
	}
}