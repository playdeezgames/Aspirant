#pragma once
#include "DescriptorManager.h"
namespace aspirant::editor::context
{
	class EditorDescriptorSelectorContext
	{
	private:
		const aspirant::game::DescriptorManager& descriptors;
	public:
		EditorDescriptorSelectorContext
		(
			const aspirant::game::DescriptorManager&
		);
	};
}