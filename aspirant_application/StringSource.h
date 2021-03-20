#pragma once
#include <string>
#include "json.hpp"
namespace tggd::data
{
	class StringSource
	{
	private:
		std::string value;
		bool indirect;
		std::string key;
	public:
		StringSource() = default;
		StringSource(const StringSource&) = default;
		StringSource(StringSource&&) = default;
		StringSource& operator=(const StringSource&) = default;
		StringSource& operator=(StringSource&&) = default;
		StringSource(const std::string&, bool);
		operator const std::string& () const;
		static StringSource FromJSON(const nlohmann::json&);
	};
}