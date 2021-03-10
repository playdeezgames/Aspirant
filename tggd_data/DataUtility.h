#pragma once
#include <string>
#include "json.hpp"
#include "IValue.h"
#include "IDataStore.h"
namespace tggd::data
{
	class DataUtility
	{
	public:
		static IValue<std::string>* LoadString(const IDataStore<std::string>&, const nlohmann::json&);
		static IValue<int>* LoadInt(const IDataStore<int>&, const nlohmann::json&);
		static IValue<bool>* LoadFlag(const IDataStore<bool>&, const nlohmann::json&);
	};
}

