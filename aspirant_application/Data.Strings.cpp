#include "Data.Strings.h"
#include "Data.JSON.h"
#include <map>
namespace data::Strings
{
	static std::map<std::string, std::string> table;

	void Start(const std::string& filename)
	{
		auto properties = data::JSON::Load(filename);
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
