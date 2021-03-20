#include "StringSource.h"
#include "StringManager.h"
namespace tggd::data
{
#define PROPERTY_KEY "key"

	StringSource::operator const std::string& () const
	{
		if (indirect)
		{
			return StringManager::Get(key);
		}
		else
		{
			return value;
		}
	}

	StringSource::StringSource(const std::string& value, bool indirect)
		: value((indirect)?(""):(value))
		, key((indirect)?(value):(""))
		, indirect(indirect)
	{

	}

	StringSource StringSource::FromJSON(const nlohmann::json& value)
	{
		if (value.is_string())
		{
			return StringSource(value, false);
		}
		else if (value.is_object())
		{
			return StringSource(value[PROPERTY_KEY], true);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}

}