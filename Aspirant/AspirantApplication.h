#pragma once
#include "Application.h"
#include "UIState.h"
#include "FinishManager.h"
#include "TextureManager.h"
#include "SpriteManager.h"
namespace aspirant
{
	class AspirantApplication : public tggd::common::Application
	{
	private:
		UIState uiState;
		tggd::common::FinishManager finishManager;
		tggd::common::TextureManager textureManager;
		tggd::common::SpriteManager spriteManager;
		bool OnSetUIState(const UIState&);
		bool OnSdlEvent(const SDL_Event&);
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
		bool IsRunning() const;
		void Start(SDL_Renderer*);
		void Finish();
	public:
		AspirantApplication();
	};
}
