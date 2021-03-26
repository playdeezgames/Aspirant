#include "Context.Editor.PickDescriptor.h"
#include "Game.Descriptors.h"
namespace context::editor::PickDescriptor
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
	::game::descriptor::Common GetDescriptor(size_t idx)
	{
		return ::game::Descriptors::Get(::game::Descriptors::GetIdentifiers()[idx]);
	}
}