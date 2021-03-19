#pragma once
#include "EditorMenuStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "LayoutManager.h"
#include "StringManager.h"
#include "ScenarioDescriptorManager.h"
#include "EditorContext.h"
namespace aspirant::editorui
{
	enum class StartEditorItem
	{
		NEW,
		OPEN,
		BACK
	};
	class StartEditorStateHandler : public EditorMenuStateHandler<StartEditorItem>
	{
	private:
		void CreateNewScenario();
	protected:
		void ActivateItem(const StartEditorItem&);
	public:
		StartEditorStateHandler
		(
			tggd::common::MessageHandler*,
			aspirant::editor::context::EditorContext&,
			const aspirant::commonui::UIContext&
		);
	};
}
