#pragma once
#include <string>
#include "CommonDescriptor.h"
#include "ScenarioObjectInstance.h"
#include <vector>
namespace aspirant::game::DescriptorManager
{
	void Start(const std::string&);
	const aspirant::game::CommonDescriptor* Get(const std::string&);
	const std::vector<std::string>& GetIdentifiers();
}