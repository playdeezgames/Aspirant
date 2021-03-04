#pragma once
#include <string>
#include "BaseDescriptor.h"
namespace aspirant
{
	class ScenarioObjectInstance
	{
	private:
		const BaseDescriptor& descriptor;
	public:
		ScenarioObjectInstance(const BaseDescriptor&);
		const BaseDescriptor& GetDescriptor() const
		{
			return descriptor;
		}
		virtual bool CanCover(const ScenarioObjectInstance*) const = 0;
	};
}