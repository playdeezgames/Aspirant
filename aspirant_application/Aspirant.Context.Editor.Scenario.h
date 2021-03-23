#pragma once
#include "Scenario.h"
namespace aspirant::context::editor::Scenario
{
	aspirant::game::Scenario& Get();
	void Save();
	void Load();
}
