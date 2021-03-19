#include "RNGUtility.h"
#include <stdlib.h>
#include <time.h>
namespace tggd::common
{
	void RNGUtility::SeedRandomNumberGenerator()
	{
		srand((unsigned int)time(nullptr));
	}

	int RNGUtility::GenerateRandomNumberFromRange(int minimum, int maximum)
	{
		return rand() % (maximum - minimum) + minimum;
	}
}

