#include "FlagManager.h"
#include "JSONUtility.h"
namespace tggd::data
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
		auto properties = tggd::data::JSONUtility::LoadJSON(fileName);
		for (auto& item : properties)
		{
			Set(item);
		}
	}

	const bool FLAG_PRESENT = true;
	const bool FLAG_ABSENT = false;

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
		if ((*this)[key])
		{
			Clear(key);
		}
		else
		{
			Set(key);
		}
	}

	const bool& FlagManager::operator[](const std::string& key) const
	{
		return (flags.contains(key)) ? (FLAG_PRESENT) : (FLAG_ABSENT);
	}
}