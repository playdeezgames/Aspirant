#pragma once
#include "CommonDescriptorManager.h"
#include <string>
#include "BaseDescriptor.h"
namespace aspirant
{
	class DescriptorManager: public tggd::common::CommonDescriptorManager<BaseDescriptor>
	{
	protected:
		BaseDescriptor* ParseDescriptor(const nlohmann::json&);
	public:
		DescriptorManager(tggd::common::FinishManager& finishManager)
			: CommonDescriptorManager(finishManager)
		{

		}
	};
}