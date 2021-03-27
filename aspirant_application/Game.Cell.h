#pragma once
#include "Game.Object.Common.h"
#include <optional>
namespace game
{
	class Cell
	{
	private:
		nlohmann::json& model;
		size_t column;
		size_t row;
	public:
		Cell(nlohmann::json&, size_t, size_t);
		game::object::Common AddObject(const game::descriptor::Common&);
		std::vector<::game::object::Common> GetObjects() const;
		std::optional<game::object::Common> GetObject() const;
		bool HasObjects() const;
		size_t GetColumn() const;
		size_t GetRow() const;
		bool RemoveObject();
	};
}
