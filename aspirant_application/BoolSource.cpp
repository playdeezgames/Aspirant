#include "BoolSource.h"
#include "FlagManager.h"
namespace tggd::data
{
#define PROPERTY_KEY "key"

	BoolSource::operator bool() const
	{
		if (indirect)
		{
			return FlagManager::Get(key);
		}
		else
		{
			return value;
		}
	}

	BoolSource BoolSource::FromJSON(const nlohmann::json& value)
	{
		if (value.is_boolean())
		{
			return BoolSource((bool)value);
		}
		else if (value.is_object())
		{
			return BoolSource((const std::string&)value[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}