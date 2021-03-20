#pragma once
#include <string>
#include "json.hpp"
namespace tggd::data
{
	class IntSource
	{
	private:
		int value;
		bool indirect;
		std::string key;
	public:
		IntSource() = default;
		IntSource(const IntSource&) = default;
		IntSource(IntSource&&) = default;
		IntSource& operator=(const IntSource&) = default;
		IntSource& operator=(IntSource&&) = default;
		IntSource(int value)
			: value(value)
			, indirect(false)
			, key("")
		{

		}
		IntSource(const std::string& key)
			: value(0)
			, indirect(true)
			, key(key)
		{

		}
		operator int() const;
		static IntSource FromJSON(const nlohmann::json&);
	};
}
