#pragma once
#include "CommonEditorStateHandler.h"
#include "EditorContext.h"
namespace aspirant
{
	class EditNavigateRoomStateHandler : public CommonEditorStateHandler
	{
	protected:
		bool OnCommand(const Command&);
		bool OnUpdate(int);
	public:
		EditNavigateRoomStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const UIContext&
		);
	};
}
