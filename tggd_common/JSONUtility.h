#pragma once
#include <string>
#include "json.hpp"
namespace tggd::data
{
	class JSONUtility
	{
	public:
		static nlohmann::json LoadJSON(const std::string&);
		static void SaveJSON(const std::string&, const nlohmann::json&);
	};
}