#include "State.ConfirmQuit.h"
#include "Application.h"
#include "UIState.h"
#include "Graphics.Layouts.h"
#include <map>
#include "MenuItem.h"
#include "Data.Strings.h"
namespace state::ConfirmQuit
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
	static std::map<ConfirmQuitItem, ::MenuItem<ConfirmQuitItem>> items = 
	{
		{ConfirmQuitItem::YES,
			::MenuItem<ConfirmQuitItem>(CONFIRM_ITEM_YES_COLOR_NAME, ConfirmQuitItem::NO, ConfirmQuitItem::NO)},
		{ConfirmQuitItem::NO,
			::MenuItem<ConfirmQuitItem>(CONFIRM_ITEM_NO_COLOR_NAME, ConfirmQuitItem::YES, ConfirmQuitItem::YES)}
	};

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
			MenuItem<ConfirmQuitItem>::Previous(current, items);
			break;
		case ::Command::DOWN:
			MenuItem<ConfirmQuitItem>::Next(current, items);
			break;
		case ::Command::GREEN:
			ActivateItem();
			break;
		case ::Command::BACK:
			::Application::SetUIState(::UIState::MAIN_MENU);
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
		MenuItem<ConfirmQuitItem>::Update(items, current);
	}

	void Start()
	{
		::Application::SetCommandHandler(::UIState::CONFIRM_QUIT, OnCommand);
		::Application::SetRenderLayout(::UIState::CONFIRM_QUIT, LAYOUT_NAME);
		::Application::SetUpdateHandler(::UIState::CONFIRM_QUIT, OnUpdate);
	}
}
