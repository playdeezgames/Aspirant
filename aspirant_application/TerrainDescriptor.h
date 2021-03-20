#pragma once
#include "CommonDescriptor.h"
namespace aspirant::game
{
	class TerrainDescriptor : public CommonDescriptor
	{
	public:
		TerrainDescriptor(const std::string&, const nlohmann::json&);
		ScenarioObjectInstance* CreateObject() const;
	};
}
