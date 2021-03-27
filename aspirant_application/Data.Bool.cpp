#include "Data.Bool.h"
#include "Data.Bools.h"
#include "Data.Properties.h"
namespace data
{
	Bool::operator bool() const
	{
		if (model.is_boolean())
		{
			return (bool)model;
		}
		else if (model.is_object())
		{
			return ::data::Bools::Read(model[Properties::KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}