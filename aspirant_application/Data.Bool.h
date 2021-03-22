#pragma once
#include <string>
#include "json.hpp"
namespace data
{
	class Bool
	{
	private:
		bool value;
		bool indirect;
		std::string key;
	public:
		Bool() = default;
		Bool(const Bool&) = default;
		Bool(Bool&&) = default;
		Bool& operator=(const Bool&) = default;
		Bool& operator=(Bool&&) = default;
		Bool(bool value)
			: value(value)
			, indirect(false)
			, key("")
		{

		}
		Bool(const std::string& key)
			: value(0)
			, indirect(true)
			, key(key)
		{

		}
		operator bool() const;
		static Bool FromJSON(const nlohmann::json&);
	};
}
