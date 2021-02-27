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
#include "IntManager.h"
#include "FlagManager.h"
#include "SoundManager.h"
#include "OptionsManager.h"
#include "DescriptorManager.h"
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
		tggd::common::IntManager intManager;
		tggd::common::FlagManager flagManager;
		tggd::common::SoundManager soundManager;
		DescriptorManager descriptorManager;
		OptionsManager optionsManager;
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
