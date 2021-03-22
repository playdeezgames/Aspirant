#include "Data.String.h"
#include "StringManager.h"
namespace data
{
#define PROPERTY_KEY "key"

	String::operator const std::string& () const
	{
		if (indirect)
		{
			return tggd::data::StringManager::Get(key);
		}
		else
		{
			return value;
		}
	}

	String::String(const std::string& value, bool indirect)
		: value((indirect)?(""):(value))
		, key((indirect)?(value):(""))
		, indirect(indirect)
	{

	}

	String String::FromJSON(const nlohmann::json& value)
	{
		if (value.is_string())
		{
			return String(value, false);
		}
		else if (value.is_object())
		{
			return String(value[PROPERTY_KEY], true);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}

}