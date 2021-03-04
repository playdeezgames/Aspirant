#pragma once
#include "BaseDescriptor.h"
namespace aspirant
{
	class TerrainDescriptor: public BaseDescriptor
	{
	public:
		TerrainDescriptor(const nlohmann::json&);
	};
}
