#pragma once
#include "Application.h"
#include "UIState.h"
#include "FinishManager.h"
#include "TextureManager.h"
#include "SpriteManager.h"
#include "ColorManager.h"
#include "FontManager.h"
#include "LayoutManager.h"
#include "StringManager.h"
namespace aspirant
{
	class AspirantApplication : public tggd::common::Application
	{
	private:
		UIState uiState;
		tggd::common::FinishManager finishManager;
		tggd::common::TextureManager textureManager;
		tggd::common::SpriteManager spriteManager;
		tggd::common::ColorManager colorManager;
		tggd::common::FontManager fontManager;
		tggd::common::LayoutManager layoutManager;
		tggd::common::StringManager stringManager;
		bool OnSetUIState(const UIState&);
		bool OnKeyDown(const SDL_KeyboardEvent&);
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
