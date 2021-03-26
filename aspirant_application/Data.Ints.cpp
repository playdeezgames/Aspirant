#include "Data.Ints.h"
#include "Data.JSON.h"
#include <map>
namespace data::Ints
{
	static nlohmann::json table;
	const int defaultInt = 0;

	void Start(const std::string& fileName)
	{
		table = data::JSON::Load(fileName);
	}

	int Get(const std::string& key)
	{
		auto iter = table.find(key);
		if (iter != table.end())
		{
			return *iter;
		}
		return defaultInt;
	}

	void Set(const std::string& key, const int& value)
	{
		table[key] = value;
	}
}