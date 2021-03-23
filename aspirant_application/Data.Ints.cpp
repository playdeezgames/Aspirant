#include "Data.Ints.h"
#include "Data.JSON.h"
#include <map>
namespace data::Ints
{
	static std::map<std::string, int> table;

	void Start
	(
		const std::string& fileName
	)
	{
		auto properties = data::JSON::Load(fileName);
		for (auto& item : properties.items())
		{
			Set(item.key(), item.value());
		}
	}

	const int& Get(const std::string& key)
	{
		return table.find(key)->second;
	}

	void Set(const std::string& key, const int& value)
	{
		table[key] = value;
	}
}