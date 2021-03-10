#pragma once
#include <string>
#include <map>
#include "IDataStore.h"
namespace tggd::common
{
	class IntManager : public tggd::data::IDataStore<int>
	{
	private:
		std::map<std::string, int> table;
	public:
		IntManager();
		void Start(const std::string&);
		const int& Get(const std::string&) const;
		void Set(const std::string&, const int&);
	};
}
