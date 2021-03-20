#pragma once
#include <string>
#include "json.hpp"
namespace tggd::data::JSONUtility
{
	nlohmann::json LoadJSON(const std::string&);
	void SaveJSON(const std::string&, const nlohmann::json&);
}