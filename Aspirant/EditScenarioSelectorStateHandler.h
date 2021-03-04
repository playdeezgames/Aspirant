#pragma once
#include "CommonStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
#include "EditorContext.h"
#include "ScenarioDescriptorManager.h"
#include "StringManager.h"
namespace aspirant
{
	class EditScenarioSelectorStateHandler : public CommonStateHandler
	{
	private:
		EditorContext& editorContext;
		const ScenarioDescriptorManager& scenarios;
		tggd::common::StringManager& stringManager;
		void UpdateIndexText(const ScenarioDescriptor*);
		void UpdateNameText(const ScenarioDescriptor*);
		void UpdateIdText(const ScenarioDescriptor*);
		void UpdateBriefText(const ScenarioDescriptor*);
		void NextScenario();
		void PreviousScenario();
		void LoadScenario();
	protected:
		bool OnCommand(const Command&);
		bool OnUpdate(int);
	public:
		EditScenarioSelectorStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&,
			EditorContext&,
			const ScenarioDescriptorManager&,
			tggd::common::StringManager&
		);
	};
}
