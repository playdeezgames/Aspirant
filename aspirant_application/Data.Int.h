#pragma once
#include <string>
#include "json.hpp"
namespace data
{
	class Int
	{
	private:
		int value;
		bool indirect;
		std::string key;
	public:
		Int() = default;
		Int(const Int&) = default;
		Int(Int&&) = default;
		Int& operator=(const Int&) = default;
		Int& operator=(Int&&) = default;
		Int(int value)
			: value(value)
			, indirect(false)
			, key("")
		{

		}
		Int(const std::string& key)
			: value(0)
			, indirect(true)
			, key(key)
		{

		}
		operator int() const;
		static Int FromJSON(const nlohmann::json&);
	};
}
