#pragma once
#include "CommonDescriptor.h"
#include "ScenarioObjectInstance.h"
namespace aspirant::editor::context::EditorDescriptorSelectorContext
{
	size_t GetIndex();
	void SetIndex(size_t idx);
	size_t GetCount();
	const aspirant::game::CommonDescriptor* GetDescriptor(size_t);
}