#pragma once
#include "Application.h"
#include "UIState.h"
#include "UIContext.h"
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
#include "ScenarioDescriptorManager.h"
#include "EditorContext.h"
#include "RoomRenderer.h"
namespace aspirant
{
	class AspirantApplication : public tggd::common::Application
	{
	private:
		UIState uiState;
		UIContext uiContext;
		tggd::common::FinishManager finishManager;
		tggd::graphics::TextureManager textureManager;
		tggd::graphics::SpriteManager spriteManager;
		tggd::graphics::ColorManager colorManager;
		tggd::graphics::FontManager fontManager;
		tggd::graphics::LayoutManager layoutManager;
		tggd::data::StringManager stringManager;
		tggd::data::IntManager intManager;
		tggd::data::FlagManager flagManager;
		tggd::common::SoundManager soundManager;
		DescriptorManager descriptors;
		ScenarioDescriptorManager scenarios;
		OptionsManager optionsManager;
		EditorContext editorContext;
		RoomRenderer roomRenderer;
		bool OnSetUIState(const UIState&);
		bool OnKeyDown(const SDL_KeyboardEvent&);
		bool OnSdlEvent(const SDL_Event&);
		bool OnTextInput(const SDL_TextInputEvent&);
	protected:
		bool OnMessage(const tggd::common::MGeneric*);
		bool IsRunning() const;
		void Start(SDL_Renderer*);
		void Finish();
	public:
		AspirantApplication();
	};
}
