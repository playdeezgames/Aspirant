#pragma once
#include "BaseDescriptor.h"
namespace aspirant
{
	class TerrainDescriptor: public BaseDescriptor
	{
	public:
		TerrainDescriptor(const nlohmann::json&);
		BaseGameObject* LoadGameObject(const nlohmann::json&) const;
		BaseGameObject* NewGameObject() const;
	};
}
