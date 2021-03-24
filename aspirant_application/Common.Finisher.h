#pragma once
#include <vector>
#include <string>
#include <map>
namespace common::Finisher
{
	template<typename TDelete>
	void Finish(TDelete*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
	template<typename TIdentifier, typename TDelete>
	void Finish(std::map<TIdentifier, TDelete*>& table)
	{
		for (auto& entry : table)
		{
			if (entry.second)
			{
				Finish(entry.second);
			}
		}
		table.clear();
	}
}

