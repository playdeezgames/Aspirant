#include "Graphics.Layouts.h"
#include "Graphics.Layout.h"
#include "Data.JSON.h"
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

}