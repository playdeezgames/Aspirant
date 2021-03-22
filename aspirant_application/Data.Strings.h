#pragma once
#include <string>
#include <map>
namespace data::Strings
{
	void Start(const std::string&);
	const std::string& Get(const std::string&);
	void Set(const std::string&, const std::string&);
}