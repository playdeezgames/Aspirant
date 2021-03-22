#include "Data.Strings.h"
#include "JSONUtility.h"
#include <map>
namespace tggd::data::StringManager
{
	static std::map<std::string, std::string> table;

	void Start(const std::string& filename)
	{
		auto properties = tggd::data::JSONUtility::LoadJSON(filename);
		for (auto& item : properties.items())
		{
			Set(item.key(), item.value());
		}
	}

	const std::string& Get(const std::string& identifier)
	{
		return table.find(identifier)->second;
	}

	void Set(const std::string& identifier, const std::string& value)
	{
		table[identifier] = value;

	}
}
