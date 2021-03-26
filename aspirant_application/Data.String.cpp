#include "Data.String.h"
#include "Data.Strings.h"
namespace data
{
	const std::string PROPERTY_KEY = "key";

	String::operator std::string () const
	{
		if (indirect)
		{
			return ::data::Strings::Get(key);
		}
		else
		{
			return value;
		}
	}

	String::String(const nlohmann::json& model)
		: model(model)
		, value()
		, key()
		, indirect()
	{
		if (model.is_string())
		{
			value = model;
			indirect = false;
			key = "";
		}
		else if (model.is_object())
		{
			value = "";
			indirect = true;
			key = model[PROPERTY_KEY];
		}
		else
		{
			throw "BAD VALUE!";
		}
	}

	String String::FromJSON(const nlohmann::json& value)
	{
		return String(value);
	}

}