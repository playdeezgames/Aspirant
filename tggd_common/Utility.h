#pragma once
#include <vector>
#include <string>
namespace tggd::common
{
	class Utility
	{
	public:
		static std::vector<std::string> CommandLineToStringVector(int, char**);
		static int StringToInt(const std::string&);
		static int ToPercentage(int, int);
		static size_t NextIndex(size_t, size_t);
		static size_t PreviousIndex(size_t, size_t);
		static int PositiveModulo(int, size_t);
	};
}

