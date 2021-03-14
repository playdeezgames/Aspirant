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
#include "RoomCellObjectsRenderer.h"
namespace aspirant
{
	class AspirantApplication : public tggd::common::Application
	{
	private:
		aspirant::commonui::UIState uiState;
		aspirant::commonui::UIContext uiContext;
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
		aspirant::game::DescriptorManager descriptors;
		aspirant::game::ScenarioDescriptorManager scenarios;
		aspirant::navigationui::OptionsManager optionsManager;
		aspirant::editor::context::EditorContext editorContext;
		aspirant::editorui::RoomRenderer roomRenderer;
		aspirant::editorui::RoomCellObjectsRenderer roomCellObjectsRenderer;
		bool OnSetUIState(const aspirant::commonui::UIState&);
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
