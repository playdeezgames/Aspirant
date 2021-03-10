#pragma once
#include <string>
namespace tggd::common
{
	template<typename TStored>
	class IDataStore
	{
	public:
		virtual const TStored& Get(const std::string&) const = 0;
	};
}
