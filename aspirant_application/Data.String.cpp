#include "Data.String.h"
#include "Data.Properties.h"
namespace data
{

	String::operator std::string () const
	{
		if (model.is_string())
		{
			return model;
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