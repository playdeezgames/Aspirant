#pragma once
#include <string>
#include <set>
namespace data::Bools
{
	void Start(const std::string&);
	const bool& Get(const std::string&);
	void Set(const std::string&);
	void Clear(const std::string&);
	void Toggle(const std::string&);
}
