#include "RoomRenderer.h"
namespace aspirant::editorui
{
	RoomRenderer::RoomRenderer
	(
		const EditorContext& editorContext
	)
		: editorContext(editorContext)
	{

	}

	void RoomRenderer::Draw(SDL_Renderer* renderer) const
	{
		auto room = editorContext.GetRoom();
		if (room != nullptr)
		{

		}
	}
}