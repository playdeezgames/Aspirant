#pragma once
#include <string>
#include "BaseDescriptor.h"
#include "json.hpp"
namespace aspirant::game
{
	class ScenarioObjectInstance
	{
	private:
		const aspirant::game::BaseDescriptor<ScenarioObjectInstance>& descriptor;
	public:
		ScenarioObjectInstance(const aspirant::game::BaseDescriptor<ScenarioObjectInstance>&);
		const aspirant::game::BaseDescriptor<ScenarioObjectInstance>& GetDescriptor() const
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