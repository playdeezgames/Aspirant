#pragma once
#include "CommonEditorStateHandler.h"
#include "EditorContext.h"
#include "RoomRenderer.h"
namespace aspirant::editorui
{
	class EditNavigateRoomStateHandler : public CommonEditorStateHandler
	{
	private:
		const RoomRenderer& roomRenderer;
	protected:
		bool OnCommand(const aspirant::commonui::Command&);
		bool OnUpdate(int);
		bool OnDraw(SDL_Renderer*) const;
	public:
		EditNavigateRoomStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const aspirant::commonui::UIContext&,
			const RoomRenderer&
		);
	};
}
