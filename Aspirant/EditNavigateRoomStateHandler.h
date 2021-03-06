#pragma once
#include "CommonStateHandler.h"
#include "EditorContext.h"
namespace aspirant
{
	class EditNavigateRoomStateHandler : public CommonStateHandler
	{
	private:
		EditorContext& editorContext;//TODO: into common editor state handler!
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
