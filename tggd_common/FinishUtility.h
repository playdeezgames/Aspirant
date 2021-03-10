#pragma once
#include <vector>
#include <string>
#include <map>
#include "json.hpp"
#include "IValue.h"
#include "IDataStore.h"
namespace tggd::common
{
	class FinishUtility
	{
	public:
		template<typename TDelete>
		static void SafeDelete(TDelete*& ptr)
		{
			if (ptr)
			{
				delete ptr;
				ptr = nullptr;
			}
		}
		template<typename TIdentifier, typename TDelete>
		static void SafeDeleteMap(std::map<TIdentifier, TDelete*>& table)
		{
			for (auto& entry : table)
			{
				if (entry.second)
				{
					SafeDelete(entry.second);
				}
			}
			table.clear();
		}
	};
}

