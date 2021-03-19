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
		ConfirmQuitStateHandler() = delete;
		ConfirmQuitStateHandler(const ConfirmQuitStateHandler&) = delete;
		ConfirmQuitStateHandler(ConfirmQuitStateHandler&&) = delete;
		ConfirmQuitStateHandler& operator=(const ConfirmQuitStateHandler&) = delete;
		ConfirmQuitStateHandler& operator=(ConfirmQuitStateHandler&&) = delete;
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
