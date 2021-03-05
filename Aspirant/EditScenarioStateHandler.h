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
		OPEN_ROOM,
		NEW_ROOM,
		BACK
	};
	class EditScenarioStateHandler : public MenuStateHandler<EditScenarioItem>
	{
	private:
		EditorContext& editorContext;
		void UpdateHeader();
	protected:
		bool OnUpdate();
		void ActivateItem(const EditScenarioItem&);
	public:
		EditScenarioStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const UIContext&
		);
	};
}
