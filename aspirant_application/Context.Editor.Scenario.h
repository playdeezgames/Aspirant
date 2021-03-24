#pragma once
#include "Game.Scenario.h"
namespace context::editor::Scenario
{
	::game::Scenario& Get();
	void Save();
	void Load();
}
