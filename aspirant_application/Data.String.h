#pragma once
#include <string>
#include "json.hpp"
namespace data
{
	class String
	{
	private:
		const nlohmann::json& model;
	public:
		String(const nlohmann::json&);
		operator std::string () const;
	};
}