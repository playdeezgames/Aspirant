#pragma once
#include <string>
#include <map>
#include "IDataStore.h"
namespace tggd::common
{
	class StringManager: public IDataStore<std::string>
	{
	private:
		std::map<std::string, std::string> table;
	public:
		StringManager();
		void Start(const std::string&);
		const std::string& Get(const std::string&) const;
		void Set(const std::string&, const std::string&);
	};
}
