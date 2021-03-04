#pragma once
#include "BaseDescriptor.h"
#include "ScenarioObjectInstance.h"
namespace aspirant
{
	class CreatureDescriptor : public BaseDescriptor<ScenarioObjectInstance>
	{
	public:
		CreatureDescriptor(const nlohmann::json&);
		ScenarioObjectInstance* CreateObject() const;
	};
}
