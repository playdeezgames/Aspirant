#include "Graphics.Layouts.h"
#include "Data.JSON.h"
#include "Common.Finishers.h"
#include "Common.Finisher.h"
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

	graphics::Layout Get(const std::string& key)
	{
		return graphics::Layout(layouts[key]);
	}

}