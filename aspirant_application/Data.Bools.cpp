#include "Data.Bools.h"
#include "Data.JSON.h"
#include <set>
namespace data::Bools
{
	static nlohmann::json table;
	const bool defaultBool = false;

	void Start(const std::string& fileName)
	{
		table = data::JSON::Load(fileName);
	}

	void Set(const std::string& key)
	{
		table[key] = true;
	}

	void Clear(const std::string& key)
	{
		table[key] = false;
	}

	void Toggle(const std::string& key)
	{
		if (Get(key))
		{
			Clear(key);
		}
		else
		{
			Set(key);
		}
	}

	bool Get(const std::string& key)
	{
		auto iter = table.find(key);
		if (iter != table.end())
		{
			return *iter;
		}
		return defaultBool;
	}
}