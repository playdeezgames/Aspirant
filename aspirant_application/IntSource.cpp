#include "IntSource.h"
#include "IntManager.h"
namespace tggd::data
{
#define PROPERTY_KEY "key"

	IntSource::operator int() const
	{
		if (indirect)
		{
			return IntManager::Get(key);
		}
		else
		{
			return value;
		}
	}

	IntSource IntSource::FromJSON(const nlohmann::json& value)
	{
		if (value.is_number_integer())
		{
			return IntSource((int)value);
		}
		else if (value.is_object())
		{
			return IntSource((const std::string&)value[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}