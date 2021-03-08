#pragma once
#include "CommonEditorStateHandler.h"
#include "EditorContext.h"
#include "RoomRenderer.h"
namespace aspirant
{
	class EditNavigateRoomStateHandler : public CommonEditorStateHandler
	{
	private:
		const RoomRenderer& roomRenderer;
	protected:
		bool OnCommand(const Command&);
		bool OnUpdate(int);
	public:
		EditNavigateRoomStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const UIContext&,
			const RoomRenderer&
		);
	};
}
