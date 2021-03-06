#pragma once
#include "EditorContext.h"
namespace aspirant
{
	class EditorContextClient
	{
	private:
		EditorContext& editorContext;
	protected:
		EditorContext& GetEditorContext() const
		{
			return editorContext;
		}
	public:
		EditorContextClient(EditorContext& editorContext)
			: editorContext(editorContext)
		{

		}
	};
}
