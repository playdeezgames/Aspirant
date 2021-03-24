#pragma once
#include "Aspirant.UIState.h"
#include "Command.h"
#include <string>
#include <SDL.h>
namespace Application
{
	void SetUIState(const aspirant::UIState&);

	typedef void (*CommandHandler)(const ::Command&);
	typedef void (*TextInputHandler)(const std::string&);
	typedef void (*UpdateHandler)(const Uint32&);
	typedef void (*RenderHandler)(SDL_Renderer*);

	void SetCommandHandler(const aspirant::UIState&, CommandHandler);
	void SetTextInputHandler(const aspirant::UIState&, TextInputHandler);
	void SetUpdateHandler(const aspirant::UIState&, UpdateHandler);
	void SetRenderHandler(const aspirant::UIState&, RenderHandler);
}
