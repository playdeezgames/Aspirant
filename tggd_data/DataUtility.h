#pragma once
#include <string>
#include "json.hpp"
#include "IValue.h"
#include "IDataStore.h"
namespace tggd::data
{
	class DataUtility
	{
		DataUtility() = delete;
		DataUtility(const DataUtility&) = delete;
		DataUtility(DataUtility&&) = delete;
		DataUtility& operator=(const DataUtility&) = delete;
		DataUtility& operator=(DataUtility&&) = delete;
	public:
		static IValue<std::string>* LoadString(const IDataStore<std::string>&, const nlohmann::json&);
		static IValue<int>* LoadInt(const IDataStore<int>&, const nlohmann::json&);
		static IValue<bool>* LoadFlag(const IDataStore<bool>&, const nlohmann::json&);
	};
}

