#pragma once
#include "CommonEditorStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "EditorContext.h"
#include "ScenarioDescriptorManager.h"
#include "StringManager.h"
namespace aspirant
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
		bool OnCommand(const Command&);
		bool OnUpdate(int);
	public:
		EditScenarioSelectorStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const UIContext&
		);
	};
}
