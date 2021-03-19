#pragma once
#include <string>
#include "json.hpp"
namespace tggd::data
{
	class JSONUtility
	{
		JSONUtility() = delete;
		JSONUtility(const JSONUtility&) = delete;
		JSONUtility(JSONUtility&&) = delete;
		JSONUtility& operator=(const JSONUtility&) = delete;
		JSONUtility& operator=(JSONUtility&&) = delete;
	public:
		static nlohmann::json LoadJSON(const std::string&);
		static void SaveJSON(const std::string&, const nlohmann::json&);
	};
}