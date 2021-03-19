#pragma once
#include "DescriptorManager.h"
#include <vector>
#include <string>
namespace aspirant::editor::context
{
	class EditorDescriptorSelectorContext
	{
		EditorDescriptorSelectorContext() = delete;
		EditorDescriptorSelectorContext(const EditorDescriptorSelectorContext&) = delete;
		EditorDescriptorSelectorContext(EditorDescriptorSelectorContext&&) = delete;
		EditorDescriptorSelectorContext& operator=(const EditorDescriptorSelectorContext&) = delete;
		EditorDescriptorSelectorContext& operator=(EditorDescriptorSelectorContext&&) = delete;
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
		void SetIndex(size_t idx)
		{
			index = idx;
		}
		size_t GetCount() const
		{
			return descriptorTypes.size();
		}
		const aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>* GetDescriptor(size_t) const;
	};
}