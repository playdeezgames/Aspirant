#pragma once
#include "CommonEditorStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "EditorContext.h"
#include "ScenarioDescriptorManager.h"
#include "StringManager.h"
namespace aspirant::editorui
{
	class EditScenarioSelectorStateHandler : public CommonEditorStateHandler
	{
	private:
		void UpdateIndexText(const aspirant::game::ScenarioDescriptor*);
		void UpdateNameText(const aspirant::game::ScenarioDescriptor*);
		void UpdateIdText(const aspirant::game::ScenarioDescriptor*);
		void UpdateBriefText(const aspirant::game::ScenarioDescriptor*);
		void LoadScenario();
	protected:
		bool OnCommand(const aspirant::commonui::Command&);
		bool OnUpdate(int);
	public:
		EditScenarioSelectorStateHandler
		(
			tggd::common::MessageHandler*,
			EditorContext&,
			const aspirant::commonui::UIContext&
		);
	};
}
