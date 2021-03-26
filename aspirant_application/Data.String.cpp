#include "Data.String.h"
#include "Data.Strings.h"
namespace data
{
	const std::string PROPERTY_KEY = "key";

	String::operator std::string () const
	{
		if (model.is_string())
		{
			return model;
		}
		else if (model.is_object())
		{
			return ::data::Strings::Get(model[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}

	String::String(const nlohmann::json& model)
		: model(model)
	{
	}
}