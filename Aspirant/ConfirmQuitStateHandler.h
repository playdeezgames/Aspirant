#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
#include "LayoutManager.h"
#include "StringManager.h"
#include "Command.h"
namespace aspirant
{
	enum class ConfirmQuitItem
	{
		NO,
		YES
	};
	class ConfirmQuitStateHandler : public MenuStateHandler<ConfirmQuitItem>
	{
	protected:
		void ActivateItem(const ConfirmQuitItem&);
	public:
		ConfirmQuitStateHandler
		(
			MessageHandler*,
			const UIContext&
		);
	};
}
