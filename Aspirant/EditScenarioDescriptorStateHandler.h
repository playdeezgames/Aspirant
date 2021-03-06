#pragma once
#include "MenuStateHandler.h"
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
	class EditScenarioDescriptorStateHandler : public MenuStateHandler<EditScenarioDescriptorItem>
	{
	private:
		EditorContext& editorContext;
	protected:
		bool OnCommand(const Command& command);
		bool OnUpdate();
		bool OnText(const std::string&);
		void ActivateItem(const EditScenarioDescriptorItem&);
	public:
		EditScenarioDescriptorStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const UIContext&
		);
	};
}