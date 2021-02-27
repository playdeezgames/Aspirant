#include "TerrainDescriptor.h"
namespace aspirant
{
	TerrainDescriptor::TerrainDescriptor(const nlohmann::json& properties)
		: BaseDescriptor(properties)
	{

	}

	BaseGameObject* TerrainDescriptor::LoadGameObject(const nlohmann::json&) const
	{
		throw "NOTIMPL";
	}

	BaseGameObject* TerrainDescriptor::NewGameObject() const
	{
		throw "NOTIMPL";

	}
}