#pragma once
#include "Scenario.h"
namespace aspirant::context::editor::Scenario
{
	aspirant::game::Scenario& GetScenario();
	void SaveScenario();
	void LoadScenario();
}
