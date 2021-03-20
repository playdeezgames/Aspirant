#pragma once
#include <string>
#include "json.hpp"
namespace tggd::data
{
	class BoolSource
	{
	private:
		bool value;
		bool indirect;
		std::string key;
	public:
		BoolSource() = default;
		BoolSource(const BoolSource&) = default;
		BoolSource(BoolSource&&) = default;
		BoolSource& operator=(const BoolSource&) = default;
		BoolSource& operator=(BoolSource&&) = default;
		BoolSource(bool value)
			: value(value)
			, indirect(false)
			, key("")
		{

		}
		BoolSource(const std::string& key)
			: value(0)
			, indirect(true)
			, key(key)
		{

		}
		operator bool() const;
		static BoolSource FromJSON(const nlohmann::json&);
	};
}
