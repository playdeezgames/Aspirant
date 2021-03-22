#include "Data.Bool.h"
#include "FlagManager.h"
namespace data
{
#define PROPERTY_KEY "key"

	Bool::operator bool() const
	{
		if (indirect)
		{
			return tggd::data::FlagManager::Get(key);
		}
		else
		{
			return value;
		}
	}

	Bool Bool::FromJSON(const nlohmann::json& value)
	{
		if (value.is_boolean())
		{
			return Bool((bool)value);
		}
		else if (value.is_object())
		{
			return Bool((const std::string&)value[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}