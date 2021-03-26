#pragma once
#include <string>
#include "json.hpp"
namespace data
{
	class String
	{
	private:
		std::string value;
		bool indirect;
		std::string key;
	public:
		String() = default;
		String(const String&) = default;
		String(String&&) = default;
		String& operator=(const String&) = default;
		String& operator=(String&&) = default;
		String(const std::string&, bool);
		operator std::string () const;
		static String FromJSON(const nlohmann::json&);
	};
}