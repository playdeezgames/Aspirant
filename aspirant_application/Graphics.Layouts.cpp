#include "Graphics.Layouts.h"
#include "Data.JSON.h"
#include <algorithm>
#include "Graphics.Types.h"
#include "Common.Properties.h"
#include "Graphics.Properties.h"
namespace graphics::Layout { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace graphics::Layouts
{
	std::map<std::string, nlohmann::json> layouts;
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
}
namespace graphics::Texts
{
	void SetTextText(const std::string& layoutName, const std::string& textId, const std::string& text)
	{
		for (auto& thingie : graphics::Layouts::layouts[layoutName])
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