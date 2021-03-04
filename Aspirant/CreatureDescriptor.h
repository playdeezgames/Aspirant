#pragma once
#include "CommonDescriptor.h"
namespace aspirant
{
	class CreatureDescriptor : public CommonDescriptor
	{
	public:
		CreatureDescriptor(const std::string&, const nlohmann::json&);
		ScenarioObjectInstance* CreateObject() const;
	};
}
