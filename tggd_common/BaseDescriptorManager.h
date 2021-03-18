#pragma once
#include <map>
#include <vector>
#include <string>
#include "json.hpp"
#include "Utility.h"
#include "Finisher.h"
#include "FinishManager.h"
#include "Utility.h"
#include "JSONUtility.h"
#include "FinishUtility.h"
namespace tggd::common
{
	template<typename TIdentifer, typename TDescriptor>
	class BaseDescriptorManager : public tggd::common::Finisher
	{
		BaseDescriptorManager() = delete;
		BaseDescriptorManager(const BaseDescriptorManager&) = delete;
		BaseDescriptorManager(BaseDescriptorManager&&) = delete;
		BaseDescriptorManager& operator=(const BaseDescriptorManager&) = delete;
		BaseDescriptorManager& operator=(BaseDescriptorManager&&) = delete;
	private:
		std::map<TIdentifer, TDescriptor*> descriptors;
		std::vector<TIdentifer> identifiers;
	protected:
		virtual TIdentifer ParseKey(const std::string&) = 0;
		virtual TDescriptor* ParseDescriptor(const TIdentifer&, const nlohmann::json&) = 0;
	public:
		BaseDescriptorManager(tggd::common::FinishManager& finishManager)
		{
			finishManager.Add(this);
		}
		void Start(const std::string& fileName)
		{
			nlohmann::json properties = tggd::data::JSONUtility::LoadJSON(fileName);
			for (auto& item : properties.items())
			{
				auto identifier = ParseKey(item.key());
				identifiers.push_back(identifier);
				descriptors[identifier] =
					ParseDescriptor(identifier, item.value());
			}
		}
		void Finish()
		{
			tggd::common::FinishUtility::SafeDeleteMap(descriptors);
		}
		const std::vector<TIdentifer>& GetTypes() const
		{
			return identifiers;
		}
		const TDescriptor* GetDescriptor(TIdentifer identifier) const
		{
			auto iter = descriptors.find(identifier);
			if (iter != descriptors.end())
			{
				return iter->second;
			}
			return nullptr;
		}
	};
}