#include "Data.Int.h"
#include "Data.Ints.h"
#include "Data.Properties.h"
namespace data
{
	Int::operator int() const
	{
		if (model.is_number_integer())
		{
			return (int)model;
		}
		else if (model.is_object())
		{
			return ::data::Ints::Read(model[Properties::KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}