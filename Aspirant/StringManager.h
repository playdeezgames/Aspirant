#pragma once
#include <string>
#include <map>
#include "json.hpp"
namespace tggd::common
{
	class StringManager
	{
	private:
		std::map<std::string, std::string> table;
	public:
		StringManager(const nlohmann::json&);
		const std::string& Get(const std::string&) const;
		void Set(const std::string&, const std::string&);
	};
}
