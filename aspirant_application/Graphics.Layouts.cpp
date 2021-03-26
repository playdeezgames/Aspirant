#include "Graphics.Layouts.h"
#include "Data.JSON.h"
#include "Common.Finishers.h"
#include "Common.Finisher.h"
namespace graphics::Layouts
{
	static std::map<std::string, nlohmann::json> layouts;
	static nlohmann::json table;
	static std::map<std::string, graphics::Layout*> descriptors;

	graphics::Layout* ParseDescriptor(const std::string& key, const std::string& fileName)
	{
		layouts[key]=data::JSON::Load(fileName);
		return new graphics::Layout(layouts[key]);
	}


	static void Finish()
	{
		common::Finisher::Finish(descriptors);
	}

	void Start(const std::string& fileName)
	{
		::common::Finishers::Add(Finish);
		table = data::JSON::Load(fileName);
		for (auto& item : table.items())
		{
			descriptors[item.key()] = ParseDescriptor(item.key(), item.value());
		}
	}

	const graphics::Layout& Get(const std::string& key)
	{
		return *descriptors[key];
	}

}