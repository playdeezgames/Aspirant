#pragma once
#include "CommonEditorStateHandler.h"
#include "LayoutManager.h"
#include "EditorContext.h"
#include "ScenarioDescriptorManager.h"
#include "StringManager.h"
namespace aspirant
{
	class EditPickRoomStateHandler : public CommonEditorStateHandler
	{
	protected:
		bool OnCommand(const Command&);
		bool OnUpdate(int);
	public:
		EditPickRoomStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const UIContext&
		);
	};
}
