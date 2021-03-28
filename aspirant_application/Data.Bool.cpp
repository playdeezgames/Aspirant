#include "Data.Bool.h"
#include "Data.Properties.h"
namespace data
{
	Bool::operator bool() const
	{
		if (model.is_boolean())
		{
			return (bool)model;
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}