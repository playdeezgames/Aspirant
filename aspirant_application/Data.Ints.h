#pragma once
#include <string>
namespace data::Ints
{
	void InitializeFromFile(const std::string&);
	int Read(const std::string&);
	void Write(const std::string&, const int&);
}
