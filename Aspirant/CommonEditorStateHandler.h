#pragma once
#include "CommonStateHandler.h"
#include "EditorContextClient.h"
namespace aspirant
{
	class CommonEditorStateHandler: public CommonStateHandler, public EditorContextClient
	{
	public:
		CommonEditorStateHandler
		(
			MessageHandler* parent,
			const UIState& filterState,
			const std::string& layoutName,
			const UIContext& uiContext,
			EditorContext& editorContext
		)
			: CommonStateHandler(parent, filterState, layoutName, uiContext)
			, EditorContextClient(editorContext)
		{

		}
	};
}