#include "Graphics.Layouts.h"
#include "Data.JSON.h"
#include <algorithm>
#include "Graphics.Types.h"
#include "Common.Properties.h"
#include "Graphics.Properties.h"
namespace graphics::Layout { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace graphics::Layouts
{
	static std::map<std::string, nlohmann::json> layouts;
	static nlohmann::json table;

	void Start(const std::string& fileName)
	{
		table = data::JSON::Load(fileName);
		for (auto& item : table.items())
		{
			layouts[item.key()] = data::JSON::Load(item.value());
		}
	}

	void Draw(SDL_Renderer* renderer, const std::string& layoutName)
	{
		graphics::Layout::Draw(renderer, layouts[layoutName]);
	}

	std::optional<int> GetMenuValue(const std::string& layoutName, const std::string& menuId)
	{
		for (auto& thingie : layouts[layoutName])
		{
			if (thingie[common::Properties::TYPE] == graphics::Types::MENU &&
				thingie[graphics::Properties::MENU_ID] == menuId)
			{
				int index = thingie[graphics::Properties::INDEX];//TODO: this cannot be proxied!
				return (int)thingie[graphics::Properties::MENU_ITEMS][index][graphics::Properties::VALUE];
			}
		}
		return std::optional<int>();
	}

	static void ChangeMenuIndex(const std::string& layoutName, const std::string& menuId, int delta)
	{
		for (auto& thingie : layouts[layoutName])
		{
			if (thingie[common::Properties::TYPE] == graphics::Types::MENU &&
				thingie[graphics::Properties::MENU_ID] == menuId)
			{
				auto itemCount = thingie[graphics::Properties::MENU_ITEMS].size();
				//TODO: this cannot be proxied! vv
				thingie[graphics::Properties::INDEX] = (thingie[graphics::Properties::INDEX] + itemCount + delta) % itemCount;
			}
		}
	}

	void NextMenuIndex(const std::string& layoutName, const std::string& menuId)
	{
		ChangeMenuIndex(layoutName, menuId, 1);
	}

	void PreviousMenuIndex(const std::string& layoutName, const std::string& menuId)
	{
		ChangeMenuIndex(layoutName, menuId, -1);
	}

	void SetMenuItemText(const std::string& layoutName, const std::string& menuItemId, const std::string& text)
	{
		for (auto& thingie : layouts[layoutName])
		{
			if (thingie[common::Properties::TYPE] == graphics::Types::MENU)
			{
				for (auto& menuItem : thingie[graphics::Properties::MENU_ITEMS])
				{
					if (menuItem.count(graphics::Properties::MENU_ITEM_ID) > 0 && 
						menuItem[graphics::Properties::MENU_ITEM_ID]==menuItemId)
					{
						menuItem[graphics::Properties::TEXT] = text;
					}
				}
			}
		}
	}

	void SetTextText(const std::string& layoutName, const std::string& textId, const std::string& text)
	{
		for (auto& thingie : layouts[layoutName])
		{
			if (thingie[common::Properties::TYPE] == graphics::Types::TEXT)
			{
				if (thingie.count(graphics::Properties::TEXT_ID) > 0 &&
					thingie[graphics::Properties::TEXT_ID] == textId)
				{
					thingie[graphics::Properties::TEXT] = text;
				}
			}
		}
	}
}