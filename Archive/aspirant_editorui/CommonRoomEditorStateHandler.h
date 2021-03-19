#pragma once
#include "CommonEditorStateHandler.h"
#include "RoomRenderer.h"
#include "RoomCellObjectsRenderer.h"
#include "DescriptorSelectorRenderer.h"
namespace aspirant::editorui
{
	class CommonRoomEditorStateHandler : public CommonEditorStateHandler
	{
	protected:
		const aspirant::editor::controls::RoomRenderer& roomRenderer;
		const aspirant::editor::controls::RoomCellObjectsRenderer& roomCellObjectsRenderer;
		const aspirant::editor::controls::DescriptorSelectorRenderer& descriptorSelectorRenderer;
	public:
		CommonRoomEditorStateHandler
		(
			MessageHandler* parent,
			const aspirant::commonui::UIState& filterState,
			const std::string& layoutName,
			const aspirant::commonui::UIContext& uiContext,
			aspirant::editor::context::EditorContext& editorContext,
			const aspirant::editor::controls::RoomRenderer& roomRenderer,
			const aspirant::editor::controls::RoomCellObjectsRenderer& roomCellObjectsRenderer,
			const aspirant::editor::controls::DescriptorSelectorRenderer& descriptorSelectorRenderer
		)
			: CommonEditorStateHandler(parent, filterState, layoutName, uiContext, editorContext)
			, roomRenderer(roomRenderer)
			, roomCellObjectsRenderer(roomCellObjectsRenderer)
			, descriptorSelectorRenderer(descriptorSelectorRenderer)
		{

		}
	};
}
