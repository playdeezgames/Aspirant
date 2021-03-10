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

	void Utility::SeedRandomNumberGenerator()
	{
		srand((unsigned int)time(nullptr));
	}

	int Utility::StringToInt(const std::string& text)
	{
		std::stringstream ss;
		ss.str(text);
		int result = 0;
		ss >> result;
		return result;
	}

	int Utility::GenerateRandomNumberFromRange(int minimum, int maximum)
	{
		return rand() % (maximum - minimum) + minimum;
	}

	const std::string PROPERTY_KEY = "key";
	IValue<std::string>* Utility::LoadString(const IDataStore<std::string>& stringStore, const nlohmann::json& value)
	{
		if (value.is_string())
		{
			return new ConstantValue<std::string>(value);
		}
		else if (value.is_object())
		{
			return new DynamicValue<std::string>(stringStore, value[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
	IValue<int>* Utility::LoadInt(const IDataStore<int>& intStore, const nlohmann::json& value)
	{
		if (value.is_number_integer())
		{
			return new ConstantValue<int>(value);
		}
		else if (value.is_object())
		{
			return new DynamicValue<int>(intStore, value[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
	}
	IValue<bool>* Utility::LoadFlag(const IDataStore<bool>& flagStore, const nlohmann::json& value)
	{
		if (value.is_boolean())
		{
			return new ConstantValue<bool>(value);
		}
		else if (value.is_object())
		{
			return new DynamicValue<bool>(flagStore, value[PROPERTY_KEY]);
		}
		else
		{
			throw "BAD VALUE!";
		}
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

