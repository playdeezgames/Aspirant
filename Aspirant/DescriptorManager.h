#pragma once
#include "BaseDescriptorManager.h"
#include <string>
#include "BaseDescriptor.h"
namespace aspirant
{
	class DescriptorManager: public tggd::common::BaseDescriptorManager<std::string, BaseDescriptor>
	{
	protected:
		std::string ParseKey(const std::string& key)
		{
			return key;
		}
		BaseDescriptor* ParseDescriptor(const nlohmann::json&);
	public:
		DescriptorManager(tggd::common::FinishManager& finishManager)
			: BaseDescriptorManager(finishManager)
		{

		}
	};
}