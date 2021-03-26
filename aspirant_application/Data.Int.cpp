#include "Data.Int.h"
#include "Data.Ints.h"
namespace data
{
	const std::string PROPERTY_KEY = "key";

	Int::operator int() const
	{
		if (indirect)
		{
			return ::data::Ints::Read(key);
		}
		else
		{
			return value;
		}
	}

	Int Int::FromJSON(const nlohmann::json& value)
	{
		if (value.is_number_integer())
		{
			return Int((int)value);
		}
		else if (value.is_object())
		{
			return Int((const std::string&)value[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}