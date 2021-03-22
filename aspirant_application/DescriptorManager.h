#pragma once
#include <string>
#include "Game.Descriptor.Common.h"
#include "ScenarioObjectInstance.h"
#include <vector>
namespace aspirant::game::DescriptorManager
{
	void Start(const std::string&);
	const ::game::descriptor::Common* Get(const std::string&);
	const std::vector<std::string>& GetIdentifiers();
}