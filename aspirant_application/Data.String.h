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
		const nlohmann::json& model;
	public:
		String(const nlohmann::json&);
		operator std::string () const;
		static String FromJSON(const nlohmann::json&);
	};
}