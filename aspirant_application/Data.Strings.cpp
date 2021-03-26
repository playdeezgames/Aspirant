#include "Data.Strings.h"
#include "Data.JSON.h"
#include <map>
namespace data::Strings
{
	static nlohmann::json table;
	const std::string defaultString = "";

	void InitializeFromFile(const std::string& filename)
	{
		table = data::JSON::Load(filename);
	}

	std::string Get(const std::string& key)
	{
		auto iter = table.find(key);
		if (iter != table.end())
		{
			return *iter;
		}
		return defaultString;
	}

	void Set(const std::string& identifier, const std::string& value)
	{
		table[identifier] = value;
	}
}
