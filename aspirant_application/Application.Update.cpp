#include "Application.Update.h"
#include <map>
#include <vector>
#include "Application.h"
namespace application::Update
{
	static std::map<::UIState, std::vector<Handler>> handlers;

	void AddHandler(const ::UIState& state, Handler handler)
	{
		if (handlers.find(state) == handlers.end())
		{
			handlers[state] = std::vector<Handler>();
		}
		handlers[state].push_back(handler);
	}

	void Handle(Uint32 ticks)
	{
		auto iter = handlers.find(::Application::GetUIState());
		if (iter != handlers.end())
		{
			for (auto handler : iter->second)
			{
				handler(ticks);
			}
		}
	}


}