#pragma once
#include "CommonDescriptorManager.h"
#include "ScenarioDescriptor.h"
namespace aspirant
{
	class ScenarioDescriptorManager : public tggd::common::CommonDescriptorManager<ScenarioDescriptor>
	{
	protected:
		std::string ParseKey(const std::string& key)
		{
			return key;
		}
		ScenarioDescriptor* ParseDescriptor(const nlohmann::json& properties)
		{
			return new ScenarioDescriptor(properties);
		}
	public:
		ScenarioDescriptorManager(tggd::common::FinishManager& finishManager)
			: CommonDescriptorManager(finishManager)
		{

		}
	};
}
