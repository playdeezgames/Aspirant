#include "EditorDescriptorSelectorContext.h"
namespace aspirant::editor::context
{
	EditorDescriptorSelectorContext::EditorDescriptorSelectorContext
	(
		const aspirant::game::DescriptorManager& descriptors
	)
		: descriptors(descriptors)
		, descriptorTypes(descriptors.GetTypes())
		, index(0)
	{
	}
	const aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>* EditorDescriptorSelectorContext::GetDescriptor(size_t idx) const
	{
		return descriptors.GetDescriptor(descriptorTypes[idx]);
	}
}