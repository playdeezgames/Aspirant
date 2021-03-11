#pragma once
#include "CommonStateHandler.h"
#include "EditorContextClient.h"
namespace aspirant
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
			EditorContext& editorContext
		)
			: CommonStateHandler(parent, filterState, layoutName, uiContext)
			, EditorContextClient(editorContext)
		{

		}
	};
}