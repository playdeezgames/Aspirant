#include "StringManager.h"
#include "Utility.h"
namespace tggd::common
{
	StringManager::StringManager()
		:table()
	{

	}

	void StringManager::Start
	(
		const std::string& fileName
	)
	{
		auto properties = JSONUtility::LoadJSON(fileName);
		for (auto& item : properties.items())
		{
			Set(item.key(), item.value());
		}
	}

	const std::string& StringManager::Get(const std::string& key) const
	{
		return table.find(key)->second;
	}

	void StringManager::Set(const std::string& key, const std::string& value)
	{
		table[key] = value;
	}

}