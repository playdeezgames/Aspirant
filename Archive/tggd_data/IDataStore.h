#pragma once
#include <string>
namespace tggd::data
{
	template<typename TStored>
	class IDataStore
	{
	public:
		virtual const TStored& operator[](const std::string&) const = 0;
	};
}
