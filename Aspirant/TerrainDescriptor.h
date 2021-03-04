#pragma once
#include "BaseDescriptor.h"
#include "ScenarioObjectInstance.h"
namespace aspirant
{
	class TerrainDescriptor: public BaseDescriptor<ScenarioObjectInstance>
	{
	public:
		TerrainDescriptor(const nlohmann::json&);
		ScenarioObjectInstance* CreateObject() const;
	};
}
