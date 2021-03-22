#include "EditorDescriptorSelectorContext.h"
#include "DescriptorManager.h"
namespace aspirant::editor::context::EditorDescriptorSelectorContext
{
	static size_t index;

	size_t GetIndex()
	{
		return index;
	}
	void SetIndex(size_t idx)
	{
		index = idx;
	}
	size_t GetCount()
	{
		return aspirant::game::DescriptorManager::GetIdentifiers().size();
	}
	const ::game::descriptor::Common* GetDescriptor(size_t idx)
	{
		return aspirant::game::DescriptorManager::Get(aspirant::game::DescriptorManager::GetIdentifiers()[idx]);
	}
}