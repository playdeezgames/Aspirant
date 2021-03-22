#pragma once
#include "Game.Descriptor.Common.h"
#include "ScenarioObjectInstance.h"
namespace aspirant::editor::context::EditorDescriptorSelectorContext
{
	size_t GetIndex();
	void SetIndex(size_t idx);
	size_t GetCount();
	const ::game::descriptor::Common* GetDescriptor(size_t);
}