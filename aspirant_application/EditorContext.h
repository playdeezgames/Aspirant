#pragma once
#include "Scenario.h"
namespace aspirant::editor::context::EditorContext
{
	aspirant::game::Scenario& GetScenario();
	void SaveScenario();
	void LoadScenario();
}
