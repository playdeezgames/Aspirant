#pragma once
#include "MenuStateHandler.h"
#include "ScenarioDescriptorManager.h"
#include "EditorContext.h"
#include "StringManager.h"
namespace aspirant
{
	enum class EditScenarioItem
	{
		DESCRIPTOR,
		ROOMS,
		BACK
	};
	class EditScenarioStateHandler : public MenuStateHandler<EditScenarioItem>
	{
	private:
		const ScenarioDescriptorManager& scenarios;
		const EditorContext& editorContext;
		void UpdateHeader();
	protected:
		bool OnUpdate();
		void ActivateItem(const EditScenarioItem&);
	public:
		EditScenarioStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&,
			tggd::common::StringManager&,
			const ScenarioDescriptorManager&,
			const EditorContext&
		);
	};
}
