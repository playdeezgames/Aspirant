#pragma once
#include "EditorMenuStateHandler.h"
#include "Command.h"
#include "EditorContext.h"
namespace aspirant
{
	enum class EditScenarioDescriptorItem
	{
		SCENARIO_NAME,
		BRIEF,
		BACK
	};
	class EditScenarioDescriptorStateHandler : public EditorMenuStateHandler<EditScenarioDescriptorItem>
	{
	protected:
		bool OnCommand(const aspirant::commonui::Command& command);
		bool OnUpdate();
		bool OnText(const std::string&);
		void ActivateItem(const EditScenarioDescriptorItem&);
	public:
		EditScenarioDescriptorStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const aspirant::commonui::UIContext&
		);
	};
}