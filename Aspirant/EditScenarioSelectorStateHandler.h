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
		void UpdateIndexText(const ScenarioDescriptor*);
		void UpdateNameText(const ScenarioDescriptor*);
		void UpdateIdText(const ScenarioDescriptor*);
		void UpdateBriefText(const ScenarioDescriptor*);
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
