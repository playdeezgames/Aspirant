#pragma once
#include "UIStateMessageHandler.h"
#include "LayoutManager.h"
#include "StringManager.h"
#include "Command.h"
#include <SDL.h>
#include <map>
#include "MRender.h"
#include "MCommand.h"
#include "MUpdate.h"
#include "MText.h"
namespace aspirant
{
	template<typename TMenuItem>
	class MenuItemDescriptor
	{
	private:
		TMenuItem nextMenuItem;
		TMenuItem previousMenuItem;
		std::string itemColorName;
	public:
		MenuItemDescriptor():nextMenuItem(), previousMenuItem(), itemColorName() {}//MAGIC!
		MenuItemDescriptor
		(
			const std::string& itemColorName,
			const TMenuItem& previousMenuItem,
			const TMenuItem& nextMenuItem
		)
			: nextMenuItem(nextMenuItem)
			, previousMenuItem(previousMenuItem)
			, itemColorName(itemColorName)
		{

		}
		const TMenuItem& GetNextMenuItem() const
		{
			return nextMenuItem;
		}
		const TMenuItem& GetPreviousMenuItem() const
		{
			return previousMenuItem;
		}
		const std::string& GetItemColorName() const
		{
			return itemColorName;
		}
	};
	template<typename TMenuItem>
	class MenuStateHandler : public UIStateMessageHandler
	{
	private:
		std::string layoutName;
		std::map<TMenuItem, MenuItemDescriptor<TMenuItem>> menuItems;
		const std::string COLOR_ACTIVE = "Cyan";//TODO: make these come from config?
		const std::string COLOR_INACTIVE = "Gray";//TODO: make these come from config?
		TMenuItem menuItem;
		UIState parentState;
		void NextItem()
		{
			auto entry = menuItems.find(menuItem);
			if (entry != menuItems.end())
			{
				menuItem = entry->second.GetNextMenuItem();
			}
		}
		void PreviousItem()
		{
			auto entry = menuItems.find(menuItem);
			if (entry != menuItems.end())
			{
				menuItem = entry->second.GetPreviousMenuItem();
			}
		}
		bool OnDraw(SDL_Renderer* renderer) const
		{
			GetUIContext().GetLayoutManager().GetDescriptor(layoutName)->Draw(renderer);
			return false;
		}
	protected:
		const TMenuItem& GetMenuItem() const
		{
			return menuItem;
		}
		tggd::common::StringManager& GetStringManager() const
		{
			return GetUIContext().GetStringManager();
		}
		virtual bool OnUpdate()
		{
			for (auto& entry : menuItems)
			{
				if (entry.first == menuItem)
				{
					GetStringManager().Set(entry.second.GetItemColorName(), COLOR_ACTIVE);
				}
				else
				{
					GetStringManager().Set(entry.second.GetItemColorName(), COLOR_INACTIVE);
				}
			}
			return false;
		}
		virtual void IncreaseItem(const TMenuItem&) {}
		virtual void DecreaseItem(const TMenuItem&) {}
		virtual void ActivateItem(const TMenuItem&) = 0;
		virtual bool OnText(const std::string&) { return false; }
		virtual bool OnCommand(const Command& command)
		{
			switch (command)
			{
			case Command::RED:
			case Command::BACK:
				SetUIState(parentState);
				break;
			case Command::UP:
				PreviousItem();
				break;
			case Command::DOWN:
				NextItem();
				break;
			case Command::LEFT:
				DecreaseItem(menuItem);
				break;
			case Command::RIGHT:
				IncreaseItem(menuItem);
				break;
			case Command::GREEN:
				ActivateItem(menuItem);
				break;
			}
			return true;
		}
		bool OnMessage(const tggd::common::MGeneric* message)
		{
			if (message->GetId() == tggd::common::MRender::MSGID_Draw)
			{
				return OnDraw(static_cast<const tggd::common::MRender*>(message)->GetRenderer());
			}
			else if (message->GetId() == MCommand::MSGID_Command)
			{
				return OnCommand(static_cast<const MCommand*>(message)->GetCommand());
			}
			else if (message->GetId() == tggd::common::MUpdate::MSGID_Update)
			{
				return OnUpdate();
			}
			else if (message->GetId() == tggd::common::MText::MSGID_TextInput)
			{
				return OnText(static_cast<const tggd::common::MText*>(message)->GetText());
			}
			return false;
		}
		void AddMenuItem(const TMenuItem& item, const MenuItemDescriptor<TMenuItem>& descriptor)
		{
			menuItems[item] = descriptor;
		}
	public:
		MenuStateHandler
		(
			MessageHandler* parent,
			const UIState& filterState,
			const UIState& parentState,
			const std::string& layoutName,
			const TMenuItem& menuItem,
			const UIContext& uiContext
		)
			: UIStateMessageHandler(parent, filterState, uiContext)
			, layoutName(layoutName)
			, menuItem(menuItem)
			, menuItems()
			, parentState(parentState)
		{

		}

	};
}
