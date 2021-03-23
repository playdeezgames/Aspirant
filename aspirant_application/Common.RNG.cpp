#include "Common.RNG.h"
#include <stdlib.h>
#include <time.h>
namespace common::RNG
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