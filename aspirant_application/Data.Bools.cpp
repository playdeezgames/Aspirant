#include "Data.Bools.h"
#include "Data.JSON.h"
#include <set>
namespace data::Bools
{
	void Start
	(
		const std::string& fileName
	)
	{
		auto properties = data::JSON::Load(fileName);
		for (auto& item : properties)
		{
			Set(item);
		}
	}

	const bool FLAG_PRESENT = true;
	const bool FLAG_ABSENT = false;

	static std::set<std::string> flags;

	void Set(const std::string& key)
	{
		flags.insert(key);
	}

	void Clear(const std::string& key)
	{
		flags.erase(key);
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

	const bool& Get(const std::string& key)
	{
		return (flags.contains(key)) ? (FLAG_PRESENT) : (FLAG_ABSENT);
	}
}