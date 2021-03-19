#pragma once
namespace tggd::common
{
	class RNGUtility
	{
		RNGUtility() = delete;
		RNGUtility(const RNGUtility&) = delete;
		RNGUtility(RNGUtility&&) = delete;
		RNGUtility& operator=(const RNGUtility&) = delete;
		RNGUtility& operator=(RNGUtility&&) = delete;
	public:
		static void SeedRandomNumberGenerator();
		static int GenerateRandomNumberFromRange(int, int);
	};
}

