#pragma once
#include "CommonStateHandler.h"
#include "EditorContextClient.h"
namespace aspirant::editorui
{
	class CommonEditorStateHandler: public aspirant::commonui::CommonStateHandler, public EditorContextClient
	{
	public:
		CommonEditorStateHandler
		(
			tggd::common::MessageHandler* parent,
			const aspirant::commonui::UIState& filterState,
			const std::string& layoutName,
			const aspirant::commonui::UIContext& uiContext,
			aspirant::editor::context::EditorContext& editorContext
		)
			: CommonStateHandler(parent, filterState, layoutName, uiContext)
			, EditorContextClient(editorContext)
		{

		}
	};
}