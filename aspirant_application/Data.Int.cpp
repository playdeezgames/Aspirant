#include "Data.Int.h"
#include "Data.Properties.h"
namespace data
{
	Int::operator int() const
	{
		if (model.is_number_integer())
		{
			return (int)model;
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
}