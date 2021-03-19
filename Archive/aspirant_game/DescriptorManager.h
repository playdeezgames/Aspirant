#pragma once
#include "CommonDescriptorManager.h"
#include <string>
#include "BaseDescriptor.h"
#include "ScenarioObjectInstance.h"
namespace aspirant::game
{
	class DescriptorManager: public tggd::common::CommonDescriptorManager<aspirant::game::BaseDescriptor<ScenarioObjectInstance>>
	{
	protected:
		aspirant::game::BaseDescriptor<ScenarioObjectInstance>* ParseDescriptor(const std::string&, const nlohmann::json&);
	public:
		DescriptorManager(tggd::common::FinishManager& finishManager)
			: CommonDescriptorManager(finishManager)
		{

		}
	};
}