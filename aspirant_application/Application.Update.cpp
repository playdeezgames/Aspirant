#include "Application.Update.h"
#include <map>
#include <vector>
#include "Application.h"
namespace application::Update
{
	static std::map<::UIState, std::vector<Handler>> updateHandlers;

	void AddHandler(const ::UIState& state, Handler handler)
	{
		if (updateHandlers.find(state) == updateHandlers.end())
		{
			updateHandlers[state] = std::vector<Handler>();
		}
		updateHandlers[state].push_back(handler);
	}

	void Handle(Uint32 ticks)
	{
		auto handlers = updateHandlers.find(::Application::GetUIState());
		if (handlers != updateHandlers.end())
		{
			for (auto handler : handlers->second)
			{
				handler(ticks);
			}
		}
	}


}