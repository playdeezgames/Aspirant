#pragma once
#include <string>
#include "Game.Descriptor.Common.h"
#include "json.hpp"
namespace aspirant::game
{
	class ScenarioObjectInstance
	{
	private:
		const ::game::descriptor::Common& descriptor;
	public:
		ScenarioObjectInstance(const ::game::descriptor::Common& descriptor) : descriptor(descriptor) {}
		const ::game::descriptor::Common& GetDescriptor() const
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