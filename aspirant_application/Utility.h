#pragma once
#include <vector>
#include <string>
namespace tggd::common::Utility
{
	std::vector<std::string> CommandLineToStringVector(int, char**);
	int StringToInt(const std::string&);
	int ToPercentage(int, int);
	size_t NextIndex(size_t, size_t);
	size_t PreviousIndex(size_t, size_t);
	int PositiveModulo(int, size_t);
}

