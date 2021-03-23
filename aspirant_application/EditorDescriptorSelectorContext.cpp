#include "EditorDescriptorSelectorContext.h"
#include "Game.Descriptors.h"
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
		return ::game::Descriptors::GetIdentifiers().size();
	}
	const ::game::descriptor::Common* GetDescriptor(size_t idx)
	{
		return ::game::Descriptors::Get(::game::Descriptors::GetIdentifiers()[idx]);
	}
}