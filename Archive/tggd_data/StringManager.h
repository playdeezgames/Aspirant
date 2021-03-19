#pragma once
#include <string>
#include <map>
#include "IDataStore.h"
namespace tggd::data
{
	class StringManager: public tggd::data::IDataStore<std::string>
	{
		StringManager(const StringManager&) = delete;
		StringManager(StringManager&&) = delete;
		StringManager& operator=(const StringManager&) = delete;
		StringManager& operator=(StringManager&&) = delete;
	private:
		std::map<std::string, std::string> table;
	public:
		StringManager();
		void Start(const std::string&);
		const std::string& operator[](const std::string&) const;
		void Set(const std::string&, const std::string&);
	};
}
