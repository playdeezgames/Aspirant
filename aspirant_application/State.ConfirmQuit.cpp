#include "Aspirant.State.ConfirmQuit.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include <map>
#include "MenuItem.h"
#include "Data.Strings.h"
namespace aspirant::state::ConfirmQuit
{
	const std::string CONFIRM_ITEM_NO_COLOR_NAME = "ConfirmQuit.Color.No";
	const std::string CONFIRM_ITEM_YES_COLOR_NAME = "ConfirmQuit.Color.Yes";
	const std::string LAYOUT_NAME = "ConfirmQuit";

	enum class ConfirmQuitItem
	{
		NO,
		YES
	};

	static ConfirmQuitItem current = ConfirmQuitItem::NO;
	static std::map<ConfirmQuitItem, ::MenuItem<ConfirmQuitItem>> items;

	static void ActivateItem()
	{
		switch (current)
		{
		case ConfirmQuitItem::NO:
			::Application::SetUIState(::UIState::MAIN_MENU);
			return;
		case ConfirmQuitItem::YES:
			::Application::SetUIState(::UIState::QUIT);
			return;
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
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
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
		::Application::SetCommandHandler(::UIState::CONFIRM_QUIT, OnCommand);
		::Application::SetRenderHandler(::UIState::CONFIRM_QUIT, OnDraw);
		::Application::SetUpdateHandler(::UIState::CONFIRM_QUIT, OnUpdate);
		items[ConfirmQuitItem::YES] =
			::MenuItem<ConfirmQuitItem>(CONFIRM_ITEM_YES_COLOR_NAME, ConfirmQuitItem::NO, ConfirmQuitItem::NO);
		items[ConfirmQuitItem::NO] =
			::MenuItem<ConfirmQuitItem>(CONFIRM_ITEM_NO_COLOR_NAME, ConfirmQuitItem::YES, ConfirmQuitItem::YES);
	}
}
