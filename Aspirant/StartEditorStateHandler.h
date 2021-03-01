#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "Command.h"
#include "LayoutManager.h"
#include "StringManager.h"
namespace aspirant
{
	enum class StartEditorItem
	{
		NEW,
		BACK
	};
	class StartEditorStateHandler : public MenuStateHandler<StartEditorItem>
	{
	protected:
		void ActivateItem(const StartEditorItem&);
	public:
		StartEditorStateHandler
		(
			MessageHandler*,
			const UIState&,
			tggd::common::LayoutManager&,
			tggd::common::StringManager&
		);
	};
}
