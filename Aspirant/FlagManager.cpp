#include "FlagManager.h"
#include "Utility.h"
#include "JSONUtility.h"
namespace tggd::common
{
	FlagManager::FlagManager()
		:flags()
	{

	}

	void FlagManager::Start
	(
		const std::string& fileName
	)
	{
		auto properties = JSONUtility::LoadJSON(fileName);
		for (auto& item : properties)
		{
			Set(item);
		}
	}

	const bool FLAG_PRESENT = true;
	const bool FLAG_ABSENT = false;

	const bool& FlagManager::Get(const std::string& key) const
	{
		return (flags.contains(key)) ? (FLAG_PRESENT) : (FLAG_ABSENT);
	}

	void FlagManager::Set(const std::string& key)
	{
		flags.insert(key);
	}

	void FlagManager::Clear(const std::string& key)
	{
		flags.erase(key);
	}

	void FlagManager::Toggle(const std::string& key)
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

}