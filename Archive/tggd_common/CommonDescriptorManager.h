#pragma once
#include "BaseDescriptorManager.h"
#include <string>
namespace tggd::common
{
	template<typename TDescriptor>
	class CommonDescriptorManager : public BaseDescriptorManager<std::string, TDescriptor>
	{
		CommonDescriptorManager() = delete;
		CommonDescriptorManager(const CommonDescriptorManager&) = delete;
		CommonDescriptorManager(CommonDescriptorManager&&) = delete;
		CommonDescriptorManager& operator=(const CommonDescriptorManager&) = delete;
		CommonDescriptorManager& operator=(CommonDescriptorManager&&) = delete;
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
