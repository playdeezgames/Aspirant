#include "Utility.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include "ConstantValue.h"
#include "DynamicValue.h"
#include <direct.h>
namespace tggd::common
{
	std::vector<std::string> Utility::CommandLineToStringVector(int argc, char** argv)
	{
		std::vector<std::string> arguments(argc);
		for (int index = 0; index < argc; ++index)
		{
			arguments.push_back(std::string(argv[index]));
		}
		return arguments;
	}

	int Utility::StringToInt(const std::string& text)
	{
		std::stringstream ss;
		ss.str(text);
		int result = 0;
		ss >> result;
		return result;
	}

	int Utility::ToPercentage(int value, int maximum)
	{
		return value * 100 / maximum;
	}

	size_t Utility::NextIndex(size_t index, size_t count)
	{
		if (count > 0)
		{
			return ((index + 1) % count);
		}
		else
		{
			return (0);
		}
	}

	size_t Utility::PreviousIndex(size_t index, size_t count)
	{
		if (count > 0)
		{
			return ((index + count - 1) % count);
		}
		else
		{
			return (0);
		}

	}
}

