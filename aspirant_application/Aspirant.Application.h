#pragma once
#include "Aspirant.UIState.h"
#include "Aspirant.Command.h"
#include <string>
#include <SDL.h>
namespace aspirant::Application
{
	void SetUIState(const aspirant::UIState&);
	void SetCommandHandler(const aspirant::UIState&, aspirant::CommandHandler);
	typedef void (*TextInputHandler)(const std::string&);
	void SetTextInputHandler(const aspirant::UIState&, TextInputHandler);
	typedef void (*UpdateHandler)(const Uint32&);
	void SetUpdateHandler(const aspirant::UIState&, UpdateHandler);
	typedef void (*RenderHandler)(SDL_Renderer*);
	void SetRenderHandler(const aspirant::UIState&, RenderHandler);
}
