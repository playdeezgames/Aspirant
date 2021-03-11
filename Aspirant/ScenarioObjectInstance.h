#pragma once
#include <string>
#include "BaseDescriptor.h"
#include "json.hpp"
namespace aspirant
{
	class ScenarioObjectInstance
	{
	private:
		const aspirant::common::BaseDescriptor<ScenarioObjectInstance>& descriptor;
	public:
		ScenarioObjectInstance(const aspirant::common::BaseDescriptor<ScenarioObjectInstance>&);
		const aspirant::common::BaseDescriptor<ScenarioObjectInstance>& GetDescriptor() const
		{
			return descriptor;
		}
		virtual bool CanCover(const ScenarioObjectInstance*) const = 0;
		virtual bool IsTerrain() const = 0;
		virtual bool IsCreature() const = 0;
		virtual void FromJSON(const nlohmann::json&) = 0;
		virtual nlohmann::json ToJSON() const = 0;
	};
}