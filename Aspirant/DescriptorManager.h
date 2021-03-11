#pragma once
#include "CommonDescriptorManager.h"
#include <string>
#include "BaseDescriptor.h"
#include "ScenarioObjectInstance.h"
namespace aspirant
{
	class DescriptorManager: public tggd::common::CommonDescriptorManager<aspirant::common::BaseDescriptor<ScenarioObjectInstance>>
	{
	protected:
		aspirant::common::BaseDescriptor<ScenarioObjectInstance>* ParseDescriptor(const std::string&, const nlohmann::json&);
	public:
		DescriptorManager(tggd::common::FinishManager& finishManager)
			: CommonDescriptorManager(finishManager)
		{

		}
	};
}