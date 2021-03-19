#pragma once
#include "EditorContext.h"
namespace aspirant::editorui
{
	class EditorContextClient
	{
	private:
		aspirant::editor::context::EditorContext& editorContext;
	protected:
		aspirant::editor::context::EditorContext& GetEditorContext() const
		{
			return editorContext;
		}
	public:
		EditorContextClient(aspirant::editor::context::EditorContext& editorContext)
			: editorContext(editorContext)
		{

		}
	};
}
