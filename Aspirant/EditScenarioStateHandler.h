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
		const EditorContext& editorContext;
		void UpdateHeader();
	protected:
		bool OnUpdate();
		void ActivateItem(const EditScenarioItem&);
	public:
		EditScenarioStateHandler
		(
			MessageHandler*,
			tggd::common::LayoutManager&,
			tggd::common::StringManager&,
			const EditorContext&,
			const UIContext&
		);
	};
}
