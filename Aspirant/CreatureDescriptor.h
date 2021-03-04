#pragma once
#include "BaseDescriptor.h"
namespace aspirant
{
	class CreatureDescriptor : public BaseDescriptor
	{
	public:
		CreatureDescriptor(const nlohmann::json&);
	};
}
