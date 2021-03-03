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
		std::map<TMenuItem, MenuItemDescriptor<TMenuItem>> menuItems;
		tggd::common::StringManager& stringManager;
		const std::string COLOR_ACTIVE = "Cyan";//TODO: make these come from config?
		const std::string COLOR_INACTIVE = "Gray";//TODO: make these come from config?
		const tggd::common::Layout* layout;
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
			layout->Draw(renderer);
			return false;
		}
	protected:
		tggd::common::StringManager& GetStringManager() const
		{
			return stringManager;
		}
		virtual bool OnUpdate()
		{
			for (auto& entry : menuItems)
			{
				if (entry.first == menuItem)
				{
					stringManager.Set(entry.second.GetItemColorName(), COLOR_ACTIVE);
				}
				else
				{
					stringManager.Set(entry.second.GetItemColorName(), COLOR_INACTIVE);
				}
			}
			return false;
		}
		virtual void IncreaseItem(const TMenuItem&) {}
		virtual void DecreaseItem(const TMenuItem&) {}
		virtual void ActivateItem(const TMenuItem&) = 0;
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
			const UIState& uiState,
			const UIState& filterState,
			const UIState& parentState,
			const tggd::common::Layout* layout,
			tggd::common::StringManager& stringManager,
			const TMenuItem& menuItem
		)
			: UIStateMessageHandler(parent, uiState, filterState)
			, layout(layout)
			, menuItem(menuItem)
			, menuItems()
			, stringManager(stringManager)
			, parentState(parentState)
		{

		}

	};
}