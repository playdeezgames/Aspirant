#include "Aspirant.State.Start.h"
#include "Aspirant.Application.h"
#include "Aspirant.UIState.h"
#include "MenuItemDescriptor.h"
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
	static std::map<StartGameItem, aspirant::commonui::MenuItemDescriptor<StartGameItem>> items;

	static void ActivateItem()
	{
		switch (current)
		{
		case StartGameItem::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			break;
		case StartGameItem::EDITOR:
			aspirant::Application::SetUIState(aspirant::UIState::START_EDITOR);
			break;
		}
	}

	static void OnCommand(const aspirant::Command& command)
	{
		switch (command)
		{
		case aspirant::Command::UP:
			current = items[current].GetPreviousMenuItem();
			break;
		case aspirant::Command::DOWN:
			current = items[current].GetNextMenuItem();
			break;
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::UIState::MAIN_MENU);
			break;
		case aspirant::Command::GREEN:
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
		aspirant::Application::SetCommandHandler(aspirant::UIState::START_GAME, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::UIState::START_GAME, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::UIState::START_GAME, OnUpdate);
		items[StartGameItem::EDITOR] =
			aspirant::commonui::MenuItemDescriptor<StartGameItem>(START_GAME_EDITOR_COLOR_NAME, StartGameItem::BACK, StartGameItem::BACK);
		items[StartGameItem::BACK]=
			aspirant::commonui::MenuItemDescriptor<StartGameItem>(START_GAME_BACK_COLOR_NAME, StartGameItem::EDITOR, StartGameItem::EDITOR);

	}
}
