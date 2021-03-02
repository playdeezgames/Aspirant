#pragma once
#include "CommonStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "Layout.h"
#include "LayoutManager.h"
namespace aspirant
{
	class EditScenarioSelectorStateHandler : public CommonStateHandler
	{
	protected:
		bool OnCommand(const Command&);
	public:
		EditScenarioSelectorStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&
		);
	};
}
