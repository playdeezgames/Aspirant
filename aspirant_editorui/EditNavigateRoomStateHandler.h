#pragma once
#include "CommonRoomEditorStateHandler.h"
#include "EditorContext.h"
#include "RoomRenderer.h"
#include "RoomCellObjectsRenderer.h"
#include "DescriptorSelectorRenderer.h"
#include "XY.h"
namespace aspirant::editorui
{
	class EditNavigateRoomStateHandler : public CommonRoomEditorStateHandler
	{
	private:
		void MoveCursor(const tggd::graphics::XY<int>&);
	protected:
		bool OnCommand(const aspirant::commonui::Command&);
		bool OnUpdate(int);
		bool OnDraw(SDL_Renderer*) const;
	public:
		EditNavigateRoomStateHandler
		(
			MessageHandler*,
			aspirant::editor::context::EditorContext&,
			const aspirant::commonui::UIContext&,
			const aspirant::editor::controls::RoomRenderer&,
			const aspirant::editor::controls::RoomCellObjectsRenderer&,
			const aspirant::editor::controls::DescriptorSelectorRenderer&
		);
	};
}
