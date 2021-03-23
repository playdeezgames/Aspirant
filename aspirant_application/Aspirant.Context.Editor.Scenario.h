#pragma once
#include "Game.Scenario.h"
namespace aspirant::context::editor::Scenario
{
	::game::Scenario& Get();
	void Save();
	void Load();
}
