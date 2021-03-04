#include "TerrainDescriptor.h"
#include "TerrainInstance.h"
namespace aspirant
{
	TerrainDescriptor::TerrainDescriptor(const std::string& name, const nlohmann::json& properties)
		: CommonDescriptor(name, properties)
	{

	}

	ScenarioObjectInstance* TerrainDescriptor::CreateObject() const
	{
		return new TerrainInstance(*this);
	}

}