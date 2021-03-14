#pragma once
#include "CommonEditorStateHandler.h"
#include "EditorContext.h"
#include "RoomRenderer.h"
#include "RoomCellObjectsRenderer.h"
#include "XY.h"
namespace aspirant::editorui
{
	class EditNavigateRoomStateHandler : public CommonEditorStateHandler
	{
	private:
		const RoomRenderer& roomRenderer;
		const RoomCellObjectsRenderer& roomCellObjectsRenderer;
		void MoveCursor(const tggd::graphics::XY<int>&);
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
			const RoomRenderer&,
			const RoomCellObjectsRenderer&
		);
	};
}
