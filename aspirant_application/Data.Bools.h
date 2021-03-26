#pragma once
#include <string>
#include <set>
namespace data::Bools
{
	void InitializeFromFile(const std::string&);
	bool Read(const std::string&);
	void Set(const std::string&);
	void Clear(const std::string&);
	void Toggle(const std::string&);
}
