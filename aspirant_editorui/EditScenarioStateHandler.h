#pragma once
#include "EditorMenuStateHandler.h"
#include "ScenarioDescriptorManager.h"
#include "EditorContext.h"
#include "StringManager.h"
namespace aspirant::editorui
{
	enum class EditScenarioItem
	{
		DESCRIPTOR,
		OPEN_ROOM,
		NEW_ROOM,
		BACK
	};
	class EditScenarioStateHandler : public EditorMenuStateHandler<EditScenarioItem>
	{
	private:
		void UpdateHeader();
	protected:
		bool OnUpdate();
		void ActivateItem(const EditScenarioItem&);
	public:
		EditScenarioStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const aspirant::commonui::UIContext&
		);
	};
}
