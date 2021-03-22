#pragma once
#include "Game.Descriptor.Common.h"
namespace game::descriptor
{
	class Creature : public Common
	{
	public:
		Creature(const std::string&, const nlohmann::json&);
		aspirant::game::ScenarioObjectInstance* CreateObject() const;
	};
}
