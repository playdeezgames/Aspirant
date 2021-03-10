#include "IntManager.h"
#include "Utility.h"
#include "JSONUtility.h"
namespace tggd::common
{
	IntManager::IntManager()
		:table()
	{

	}

	void IntManager::Start
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

	const int& IntManager::Get(const std::string& key) const
	{
		return table.find(key)->second;
	}

	void IntManager::Set(const std::string& key, const int& value)
	{
		table[key] = value;
	}
}