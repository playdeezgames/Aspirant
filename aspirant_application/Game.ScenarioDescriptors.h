#pragma once
#include "Game.ScenarioDescriptor.h"
#include "Common.Finishers.h"
#include <string>
#include <vector>
namespace game::ScenarioDescriptors
{
	void Load(const std::string&);
	void Save();
	int GetNextId();
	size_t Add(::game::ScenarioDescriptor*);
	size_t GetCount();
	::game::ScenarioDescriptor* Get(size_t);
}
