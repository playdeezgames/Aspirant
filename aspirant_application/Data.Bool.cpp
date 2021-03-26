#include "Data.Bool.h"
#include "Data.Bools.h"
namespace data
{
	const std::string PROPERTY_KEY = "key";

	Bool::operator bool() const
	{
		if (indirect)
		{
			return ::data::Bools::Read(key);
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