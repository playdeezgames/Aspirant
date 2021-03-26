#include "Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
#include <SDL.h>
namespace context::editor::Scenario
{
	static ::game::Scenario scenario;

	::game::Scenario& Get()
	{
		return scenario;
	}

	void Save()
	{
		auto start = SDL_GetTicks();
		auto properties = 
			Get().ToJSON();
		auto elapsed = SDL_GetTicks() - start;
		SDL_Log("%d", elapsed);
		start = SDL_GetTicks();
		data::JSON::Save(
			::game::ScenarioDescriptors::Get(
				::context::editor::Scenarios::GetIndex())
			.GetFileName(),
			properties
			);
		elapsed = SDL_GetTicks() - start;
		SDL_Log("%d", elapsed);
	}

	void Load()
	{
		::context::editor::Scenario::Get()
			.FromJSON(
				data::JSON::Load(
					::game::ScenarioDescriptors::Get(
						::context::editor::Scenarios::GetIndex())
					.GetFileName()));
	}

}
