#include "RNGUtility.h"
#include <stdlib.h>
#include <time.h>
namespace tggd::common::RNGUtility
{
	void Seed()
	{
		srand((unsigned int)time(nullptr));
	}

	int GenerateFromRange(int minimum, int maximum)
	{
		return rand() % (maximum - minimum) + minimum;
	}

}