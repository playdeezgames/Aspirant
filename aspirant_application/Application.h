#pragma once
#include "UIState.h"
#include "Command.h"
#include <string>
#include <SDL.h>
#include "Common.XY.h"
namespace Application
{
	void SetUIState(const ::UIState&);

	typedef void (*CommandHandler)(const ::Command&);
	typedef void (*TextInputHandler)(const std::string&);
	typedef void (*UpdateHandler)(const Uint32&);
	typedef void (*MouseMotionHandler)(const common::XY<Sint32>&);

	void SetMouseMotionHandler(const UIState&, MouseMotionHandler);
	void SetCommandHandler(const UIState&, CommandHandler);
	void SetTextInputHandler(const UIState&, TextInputHandler);
	void AddUpdateHandler(const UIState&, UpdateHandler);
	void SetRenderLayout(const UIState&, const std::string&);
}
