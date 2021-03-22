#pragma once
#include <string>
#include "CommonDescriptor.h"
#include "json.hpp"
namespace aspirant::game
{
	class ScenarioObjectInstance
	{
	private:
		const aspirant::game::CommonDescriptor& descriptor;
	public:
		ScenarioObjectInstance(const aspirant::game::CommonDescriptor& descriptor) : descriptor(descriptor) {}
		const aspirant::game::CommonDescriptor& GetDescriptor() const
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