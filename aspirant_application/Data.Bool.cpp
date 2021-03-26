#include "Data.Bool.h"
#include "Data.Bools.h"
namespace data
{
	const std::string PROPERTY_KEY = "key";

	Bool::operator bool() const
	{
		if (model.is_boolean())
		{
			return (bool)model;
		}
		else if (model.is_object())
		{
			return ::data::Bools::Read(model[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}