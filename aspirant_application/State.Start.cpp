#include "Aspirant.State.Start.h"
#include "Application.h"
#include "Aspirant.UIState.h"
#include "MenuItem.h"
#include <map>
#include "Graphics.Layouts.h"
#include "Data.Strings.h"
namespace aspirant::state::Start
{
	const std::string START_GAME_EDITOR_COLOR_NAME = "StartGame.Color.Editor";
	const std::string START_GAME_BACK_COLOR_NAME = "StartGame.Color.Back";
	const std::string LAYOUT_NAME = "StartGame";

	enum class StartGameItem
	{
		EDITOR,
		BACK
	};

	static StartGameItem current = StartGameItem::BACK;
	static std::map<StartGameItem, ::MenuItem<StartGameItem>> items =
	{
		{StartGameItem::EDITOR, ::MenuItem<StartGameItem>(START_GAME_EDITOR_COLOR_NAME, StartGameItem::BACK, StartGameItem::BACK)},
		{StartGameItem::BACK, ::MenuItem<StartGameItem>(START_GAME_BACK_COLOR_NAME, StartGameItem::EDITOR, StartGameItem::EDITOR)}
	};


	static void ActivateItem()
	{
		switch (current)
		{
		case StartGameItem::BACK:
			::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			break;
		case StartGameItem::EDITOR:
			::Application::SetUIState(aspirant::UIState::START_EDITOR);
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
			::Application::SetUIState(aspirant::UIState::MAIN_MENU);
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
		::Application::SetCommandHandler(aspirant::UIState::START_GAME, OnCommand);
		::Application::SetRenderHandler(aspirant::UIState::START_GAME, OnDraw);
		::Application::SetUpdateHandler(aspirant::UIState::START_GAME, OnUpdate);
	}
}
