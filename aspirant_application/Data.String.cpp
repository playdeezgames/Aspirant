#include "Data.String.h"
#include "Data.Strings.h"
#include "Data.Properties.h"
namespace data
{

	String::operator std::string () const
	{
		if (model.is_string())
		{
			return model;
		}
		else if (model.is_object())
		{
			return ::data::Strings::Get(model[Properties::KEY]);
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