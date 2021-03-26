#pragma once
#include <string>
#include "Game.Descriptor.Common.h"
#include <vector>
namespace game::Descriptors
{
	void Start(const std::string&);
	game::descriptor::Common Get(const std::string&);
	const std::vector<std::string>& GetIdentifiers();
}