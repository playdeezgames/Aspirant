#pragma once
#include "Application.h"
#include "UIState.h"
namespace aspirant
{
	class AspirantApplication : public tggd::common::Application
	{
	private:
		UIState uiState;
		bool OnSetUIState(const UIState&);
		bool OnSdlEvent(const SDL_Event&);
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
		bool IsRunning() const;
		void Start();
		void Finish();
	public:
		AspirantApplication();
	};
}
