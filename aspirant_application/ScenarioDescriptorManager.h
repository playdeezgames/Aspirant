#pragma once
#include "ScenarioDescriptor.h"
#include "FinishManager.h"
#include <string>
#include <vector>
namespace aspirant::game::ScenarioDescriptorManager
{
	void Load(const std::string&);
	void Save();
	int GetNextId();
	size_t Add(ScenarioDescriptor*);
	size_t GetCount();
	ScenarioDescriptor* Get(size_t);
}
