#pragma once
#include <string>
#include "BaseDescriptor.h"
#include "ScenarioObjectInstance.h"
#include <vector>
namespace aspirant::game::DescriptorManager
{
	void Start(const std::string&);
	const aspirant::game::BaseDescriptor<ScenarioObjectInstance>* Get(std::string&);
	const std::vector<std::string>& GetIdentifiers();
}