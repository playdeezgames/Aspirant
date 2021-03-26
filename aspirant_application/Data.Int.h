#pragma once
#include <string>
#include "json.hpp"
namespace data
{
	class Int
	{
	private:
		const nlohmann::json& model;
	public:
		Int() = default;
		Int(const Int&) = default;
		Int(Int&&) = default;
		Int& operator=(const Int&) = default;
		Int& operator=(Int&&) = default;
		Int(const nlohmann::json& model)
			: model(model)
		{

		}
		operator int() const;
	};
}
