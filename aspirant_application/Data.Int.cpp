#include "Data.Int.h"
#include "Data.Ints.h"
namespace data
{
	const std::string PROPERTY_KEY = "key";

	Int::operator int() const
	{
		if (model.is_number_integer())
		{
			return (int)model;
		}
		else if (model.is_object())
		{
			return ::data::Ints::Read(model[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}