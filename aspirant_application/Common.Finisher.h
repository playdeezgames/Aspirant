#pragma once
#include <vector>
#include <string>
#include <map>
namespace common::Finisher
{
	template<typename TDelete>
	void SafeDelete(TDelete*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
	template<typename TIdentifier, typename TDelete>
	void SafeDeleteMap(std::map<TIdentifier, TDelete*>& table)
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
}

