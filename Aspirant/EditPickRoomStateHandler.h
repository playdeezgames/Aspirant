#pragma once
#include "CommonStateHandler.h"
#include "LayoutManager.h"
#include "EditorContext.h"
#include "ScenarioDescriptorManager.h"
#include "StringManager.h"
namespace aspirant
{
	class EditPickRoomStateHandler : public CommonStateHandler
	{
	protected:
		bool OnCommand(const Command&);
		bool OnUpdate(int);
	public:
		EditPickRoomStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&,
			EditorContext&,
			const ScenarioDescriptorManager&,
			tggd::common::StringManager&
		);
	};
}
