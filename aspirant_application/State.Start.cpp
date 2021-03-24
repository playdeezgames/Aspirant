#include "State.Start.h"
#include "Application.h"
#include "UIState.h"
#include "MenuItem.h"
#include <map>
#include "Graphics.Layouts.h"
#include "Data.Strings.h"
namespace state::Start
{
	const std::string START_GAME_EDITOR_COLOR_NAME = "StartGame.Color.Editor";
	const std::string START_GAME_BACK_COLOR_NAME = "StartGame.Color.Back";
	const std::string START_GAME_PLAY_COLOR_NAME = "StartGame.Color.Play";
	const std::string LAYOUT_NAME = "StartGame";

	enum class StartGameItem
	{
		EDITOR,
		PLAY,
		BACK
	};

	static StartGameItem current = StartGameItem::BACK;
	static std::map<StartGameItem, ::MenuItem<StartGameItem>> items =
	{
		{StartGameItem::EDITOR, ::MenuItem<StartGameItem>(START_GAME_EDITOR_COLOR_NAME, StartGameItem::BACK, StartGameItem::PLAY)},
		{StartGameItem::PLAY, ::MenuItem<StartGameItem>(START_GAME_PLAY_COLOR_NAME, StartGameItem::EDITOR, StartGameItem::BACK)},
		{StartGameItem::BACK, ::MenuItem<StartGameItem>(START_GAME_BACK_COLOR_NAME, StartGameItem::PLAY, StartGameItem::EDITOR)}
	};


	static void ActivateItem()
	{
		switch (current)
		{
		case StartGameItem::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		case StartGameItem::EDITOR:
			::Application::SetUIState(::UIState::START_EDITOR);
			break;
		}
	}

	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case ::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case ::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		graphics::Layouts::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::START_GAME, OnCommand);
		::Application::SetRenderHandler(::UIState::START_GAME, OnDraw);
		::Application::SetUpdateHandler(::UIState::START_GAME, OnUpdate);
	}
}
