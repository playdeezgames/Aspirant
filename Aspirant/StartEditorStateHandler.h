#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "LayoutManager.h"
#include "StringManager.h"
#include "ScenarioDescriptorManager.h"
#include "EditorContext.h"
namespace aspirant
{
	enum class StartEditorItem
	{
		NEW,
		OPEN,
		BACK
	};
	class StartEditorStateHandler : public MenuStateHandler<StartEditorItem>
	{
	private:
		EditorContext& editorContext;
		void CreateNewScenario();
	protected:
		void ActivateItem(const StartEditorItem&);
	public:
		StartEditorStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&,
			tggd::common::StringManager&,
			EditorContext&
		);
	};
}
