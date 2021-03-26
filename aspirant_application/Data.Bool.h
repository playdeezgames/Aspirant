#pragma once
#include <string>
#include "json.hpp"
namespace data
{
	class Bool
	{
	private:
		const nlohmann::json& model;
	public:
		Bool() = default;
		Bool(const Bool&) = default;
		Bool(Bool&&) = default;
		Bool& operator=(const Bool&) = default;
		Bool& operator=(Bool&&) = default;
		Bool(const nlohmann::json& model)
			: model(model)
		{

		}
		operator bool() const;
	};
}
