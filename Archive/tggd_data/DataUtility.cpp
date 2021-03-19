#include "DataUtility.h"
#include "ConstantValue.h"
#include "DynamicValue.h"
namespace tggd::data
{
#define PROPERTY_KEY "key"

	IValue<std::string>* DataUtility::LoadString(const IDataStore<std::string>& stringStore, const nlohmann::json& value)
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
	IValue<int>* DataUtility::LoadInt(const IDataStore<int>& intStore, const nlohmann::json& value)
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
	IValue<bool>* DataUtility::LoadFlag(const IDataStore<bool>& flagStore, const nlohmann::json& value)
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
}

