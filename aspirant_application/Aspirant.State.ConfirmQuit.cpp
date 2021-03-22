#include "Aspirant.State.ConfirmQuit.h"
#include "Aspirant.Application.h"
#include "UIState.h"
#include "LayoutManager.h"
#include <map>
#include "MenuItemDescriptor.h"
#include "StringManager.h"
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
	static std::map<ConfirmQuitItem, aspirant::commonui::MenuItemDescriptor<ConfirmQuitItem>> items;

	static void ActivateItem()
	{
		switch (current)
		{
		case ConfirmQuitItem::NO:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			return;
		case ConfirmQuitItem::YES:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::QUIT);
			return;
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
		case aspirant::Command::GREEN:
			ActivateItem();
			break;
		case aspirant::Command::BACK:
			aspirant::Application::SetUIState(aspirant::commonui::UIState::MAIN_MENU);
			break;
		}
	}

	static void OnDraw(SDL_Renderer* renderer)
	{
		tggd::graphics::LayoutManager::Get(LAYOUT_NAME).Draw(renderer);
	}

	static void OnUpdate(const Uint32& ticks)
	{
		for (auto& item : items)
		{
			tggd::data::StringManager::Set(item.second.GetItemColorName(), (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}

	void Start()
	{
		aspirant::Application::SetCommandHandler(aspirant::commonui::UIState::CONFIRM_QUIT, OnCommand);
		aspirant::Application::SetRenderHandler(aspirant::commonui::UIState::CONFIRM_QUIT, OnDraw);
		aspirant::Application::SetUpdateHandler(aspirant::commonui::UIState::CONFIRM_QUIT, OnUpdate);
		items[ConfirmQuitItem::YES] =
			aspirant::commonui::MenuItemDescriptor<ConfirmQuitItem>(CONFIRM_ITEM_YES_COLOR_NAME, ConfirmQuitItem::NO, ConfirmQuitItem::NO);
		items[ConfirmQuitItem::NO] =
			aspirant::commonui::MenuItemDescriptor<ConfirmQuitItem>(CONFIRM_ITEM_NO_COLOR_NAME, ConfirmQuitItem::YES, ConfirmQuitItem::YES);
	}
}
