#pragma once
#include "BaseDescriptorManager.h"
#include <string>
namespace tggd::common
{
	template<typename TDescriptor>
	class CommonDescriptorManager : public BaseDescriptorManager<std::string, TDescriptor>
	{
	protected:
		std::string ParseKey(const std::string& key)
		{
			return key;
		}
	public:
		CommonDescriptorManager(FinishManager& finishManager)
			: BaseDescriptorManager<std::string, TDescriptor>(finishManager)
		{

		}
	};
}
