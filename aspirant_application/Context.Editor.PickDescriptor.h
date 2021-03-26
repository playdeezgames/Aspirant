#pragma once
#include "Game.Descriptor.Common.h"
#include "Game.Object.Common.h"
namespace context::editor::PickDescriptor
{
	size_t GetIndex();
	void SetIndex(size_t idx);
	size_t GetCount();
	::game::descriptor::Common GetDescriptor(size_t);
}