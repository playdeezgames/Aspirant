#include "Graphics.Layouts.h"
#include "Graphics.Layout.h"
#include "Data.JSON.h"
#include <algorithm>
#include "Graphics.Types.h"
#include "Common.Properties.h"
#include "Graphics.Properties.h"
#include "Data.Int.h"
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

	void Draw(SDL_Renderer* renderer, const std::string& key)
	{
		graphics::Layout::Draw(renderer, layouts[key]);
	}

	std::optional<int> GetMenuValue(const std::string& key, const std::string& menuId)
	{
		for (auto& thingie : layouts[key])
		{
			if (thingie[common::Properties::TYPE] == graphics::Types::MENU &&
				thingie[graphics::Properties::MENU_ID] == menuId)
			{
				int index = thingie[graphics::Properties::INDEX];//TODO: this cannot be proxied!
				return (int)data::Int(thingie[graphics::Properties::MENU_ITEMS][index][graphics::Properties::VALUE]);
			}
		}
		return std::optional<int>();
	}

	static void ChangeMenuIndex(const std::string& key, const std::string& menuId, int delta)
	{
		for (auto& thingie : layouts[key])
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

	void NextMenuIndex(const std::string& key, const std::string& menuId)
	{
		ChangeMenuIndex(key, menuId, 1);
	}

	void PreviousMenuIndex(const std::string& key, const std::string& menuId)
	{
		ChangeMenuIndex(key, menuId, -1);
	}
}