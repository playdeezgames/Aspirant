#pragma once
#include "UIState.h"
#include "Command.h"
#include <string>
#include <SDL.h>
namespace aspirant::Application
{
	void SetUIState(const aspirant::commonui::UIState&);
	void SetCommandHandler(const aspirant::commonui::UIState&, aspirant::commonui::CommandHandler);
	typedef void (*TextInputHandler)(const std::string&);
	void SetTextInputHandler(const aspirant::commonui::UIState&, TextInputHandler);
	typedef void (*UpdateHandler)(const Uint32&);
	void SetUpdateHandler(const aspirant::commonui::UIState&, UpdateHandler);
	typedef void (*RenderHandler)(SDL_Renderer*);
	void SetRenderHandler(const aspirant::commonui::UIState&, RenderHandler);
}
