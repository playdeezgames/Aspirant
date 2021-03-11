#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "LayoutManager.h"
#include "StringManager.h"
#include "Command.h"
namespace aspirant::navigationui
{
	enum class ConfirmQuitItem
	{
		NO,
		YES
	};
	class ConfirmQuitStateHandler : public aspirant::commonui::MenuStateHandler<ConfirmQuitItem>
	{
	protected:
		void ActivateItem(const ConfirmQuitItem&);
	public:
		ConfirmQuitStateHandler
		(
			tggd::common::MessageHandler*,
			const aspirant::commonui::UIContext&
		);
	};
}
