#pragma once
#include "DescriptorManager.h"
#include <vector>
#include <string>
namespace aspirant::editor::context
{
	class EditorDescriptorSelectorContext
	{
	private:
		const aspirant::game::DescriptorManager& descriptors;
		const std::vector<std::string>& descriptorTypes;
		size_t index;
	public:
		EditorDescriptorSelectorContext
		(
			const aspirant::game::DescriptorManager&
		);
		size_t GetIndex() const
		{
			return index;
		}
		size_t GetCount() const
		{
			return descriptorTypes.size();
		}
		const aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>* GetDescriptor(size_t) const;
	};
}