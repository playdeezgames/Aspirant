#pragma once
#include "CommonDescriptor.h"
namespace aspirant
{
	class TerrainDescriptor: public CommonDescriptor
	{
	public:
		TerrainDescriptor(const std::string&, const nlohmann::json&);
		ScenarioObjectInstance* CreateObject() const;
	};
}
