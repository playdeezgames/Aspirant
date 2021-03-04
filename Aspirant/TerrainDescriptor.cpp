#include "TerrainDescriptor.h"
#include "TerrainInstance.h"
namespace aspirant
{
	TerrainDescriptor::TerrainDescriptor(const nlohmann::json& properties)
		: BaseDescriptor(properties)
	{

	}

	ScenarioObjectInstance* TerrainDescriptor::CreateObject() const
	{
		return new TerrainInstance(*this);
	}

}