#pragma once
#include "Game.ScenarioDescriptor.h"
#include <string>
#include <vector>
#include <optional>
namespace game::ScenarioDescriptors
{
	void Load(const std::string&);
	void Save();
	int GetNextId();
	size_t Add();
	size_t GetCount();
	std::optional<game::ScenarioDescriptor> Get(size_t);
}
