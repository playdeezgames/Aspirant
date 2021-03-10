#pragma once
#include <string>
namespace tggd::data
{
	template<typename TStored>
	class IDataStore
	{
	public:
		virtual const TStored& Get(const std::string&) const = 0;
	};
}
