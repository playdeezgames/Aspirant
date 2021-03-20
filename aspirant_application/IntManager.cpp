#include "IntManager.h"
#include "JSONUtility.h"
#include <map>
namespace tggd::data::IntManager
{
	static std::map<std::string, int> table;

	void Start
	(
		const std::string& fileName
	)
	{
		auto properties = tggd::data::JSONUtility::LoadJSON(fileName);
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