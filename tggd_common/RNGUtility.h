#pragma once
namespace tggd::common
{
	class RNGUtility
	{
	public:
		static void SeedRandomNumberGenerator();
		static int GenerateRandomNumberFromRange(int, int);
	};
}

