#pragma once
#include <string>
namespace tggd::data::IntManager
{
	void Start(const std::string&);
	const int& Get(const std::string&);
	void Set(const std::string&, const int&);
}
